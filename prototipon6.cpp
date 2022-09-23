#include <iostream>
#include <stdlib.h>

using namespace std;

//Classe Mapa
class Mapa{

    public:
        int comp=20;
        char mapa[75][75];
        int portal1l, portal1c;
        int portal2l, portal2c;
        int l,c;

        void Plot1(int& persol, int& persoc, bool& botao);
};

//Classe Personagem
class Personagem{
    private:

    public:
        string nome;
        char comando;
        bool chave;
        int vida=3;
        int defesa;
        bool botao=false;
        int l=10,c=10;

        void Movimento(Mapa mapa1);
};


int main(){

    //Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa mapa1;


    //União Mapa-Personagem
    while(synth.vida>=0){
    
        system("clear || cls");

        mapa1.Plot1(synth.l,synth.c,synth.botao);

        synth.Movimento(mapa1);

    }


    return 0;
}


//PLOTAGEM DO MAPA TUTORIAL
void Mapa::Plot1(int& persol, int& persoc, bool& botao){
    
    for(l=0;l<comp;l++){

            for(c=0;c<comp;c++){

                //Jogador plotado no mapa

                if(persol==l and persoc==c){
                    mapa[l][c]='&';
                    cout<<mapa[l][c]<<" ";
                }

                //Delimitação do mapa
                else if(l==0 or l==comp-1 or c==0 or c==comp-1){
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }

                //Parede da sala esquerdo-superior
                else if( (l==(comp-4)/2 and c<(comp-2)/2) or (l<(comp-2)/2 and c==(comp-4)/2) ){
                    
                    //PORTA FECHADA
                    if(l==(comp-4)/4 and c==(comp-4)/2 and botao==false){
                        mapa[l][c]='D';
                        cout<<mapa[l][c]<<" ";
                    }

                    //PORTA ABERTA
                    else if(l==(comp-4)/4 and c==(comp-4)/2 and botao==true){
                        mapa[l][c]='=';
                        cout<<mapa[l][c]<<" ";
                    }

                    else{
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                    }

                }

                //Parede da sala direita-superior
                else if( (l<=(comp-4)/2 and c==(comp+2)/2) or (l==(comp-4)/2 and c>(comp+2)/2) ){
                    
                    //PORTA ABERTA
                    if(l==(comp-4)/2 and c==(comp+4)/2){
                        mapa[l][c]='=';
                        cout<<mapa[l][c]<<" ";
                    }
                    else{
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                    }
                }

                //Parede da sala esquerdo-inferior
                else if( (l==(comp+2)/2 and c<=(comp-4)/2) or (l>(comp+2)/2 and c==(comp-4)/2) ){
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }

                //Parede da sala direita-inferior
                else if( (l==(comp+2)/2 and c>=(comp+2)/2 ) or (l>=(comp+2)/2 and c==(comp+2)/2)){
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }

                //Interior da sala direita-superior
                else if(l>0 and l<(comp-4)/2 and c>(comp+2)/2 and c<comp){
                    //Labirinto de Cacto
                    if((c==comp-7 and l>1) or (c==comp-3 and l>1) or (c==comp-5 and l<(comp+1)/3)){
                        mapa[l][c]='#';
                        cout<<mapa[l][c]<<" ";
                    }
                    //Botão
                    else if(l==comp-13 and c==comp-2){
                        mapa[l][c]='O';
                        cout<<mapa[l][c]<<" ";
                    }
                    //Vazio do mapa
                    else{
                        mapa[l][c]=' ';
                        cout<<mapa[l][c]<<" ";
                    }
                }

                //Interior da sala esquerda-superior
                else if(l>0 and l<(comp-4)/2 and c>0 and c<(comp-4)/2){
                    
                    //PORTAL 1
                    if(l==comp/5 and c==comp/5){
                    	portal1l=comp/5;
                    	portal1c=comp/5;
                        mapa[l][c]='>';
                        cout<<mapa[l][c]<<" ";
                    }

                    //Vazio do mapa
                    else{
                        mapa[l][c]=' ';
                        cout<<mapa[l][c]<<" ";
                    }

                }

                //Interior da sala esquerda-inferior
                else if(l>comp-9 and l<comp and c>0 and c<(comp-4)/2){
                    
                    //PORTAL 2
                    if(l==comp-5 and c==comp-16){
                    	portal2l=comp-5;
                    	portal2c=comp-16;
                        mapa[l][c]='<';
                        cout<<mapa[l][c]<<" ";
                    }

                    //Vazio do mapa
                    else{
                        mapa[l][c]=' ';
                        cout<<mapa[l][c]<<" ";
                    }

                }
                //Restante do mapa
                else{
                    mapa[l][c]=' ';
                    cout<<mapa[l][c]<<" ";
                }

            }

            cout<<"\n";
        }


}


//MOVIMENTAÇÃO DO PERSONAGEM PELO MAPA
void Personagem::Movimento(Mapa mapa){

    cout<<"VIDAS: "<<vida<<" BOTAO: "<<botao<<endl;
    cout<<">";
    cin>>comando;

    switch(comando){

        //PARA CIMA
        case 'W':
        case 'w':
            //Interações bloqueadas ou automáticas
            if(mapa.mapa[l-1][c]=='*' or mapa.mapa[l-1][c]=='D' or mapa.mapa[l-1][c]=='#' or mapa.mapa[l-1][c]=='O' or mapa.mapa[l-1][c]=='>' or mapa.mapa[l-1][c]=='<' ){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(mapa.mapa[l-1][c]=='#'){
                    l=l;
                    vida=vida-1;
                    botao=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                }

                //Interação com botão
                else if(mapa.mapa[l-1][c]=='O'){
                    l=l-1;
                    botao=true;
                }
                
                //Interação com portal 1
                else if(mapa.mapa[l-1][c]=='>'){
                	l=mapa.portal2l-1;
                	c=mapa.portal2c;
				}

				//Interação com portal2
				else if(mapa.mapa[l-1][c]=='<'){
                	l=mapa.portal1l-1;
                	c=mapa.portal1c;
				}
				
                else{
                    l=l;
                }
            }
            
            

            else{
                l=l-1;
            }
            break;
        

        //PARA BAIXO
        case 'S':
        case 's':
            //Interações bloqueadas ou automáticas
            if(mapa.mapa[l+1][c]=='*' or mapa.mapa[l+1][c]=='D' or mapa.mapa[l+1][c]=='#' or mapa.mapa[l+1][c]=='O' or mapa.mapa[l+1][c]=='>' or mapa.mapa[l+1][c]=='<'){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(mapa.mapa[l+1][c]=='#'){
                    l=l;
                    vida=vida-1;
                    botao=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                }

                //Interação com botão
                else if(mapa.mapa[l+1][c]=='O'){
                    l=l+1;
                    botao=true;
                }
                
    			//Interação com portal1
    			else if(mapa.mapa[l+1][c]=='>'){
    				l=mapa.portal2l+1;
                	c=mapa.portal2c;
				}
				
				//Interação com portal2
    			else if(mapa.mapa[l+1][c]=='<'){
    				l=mapa.portal1l+1;
                	c=mapa.portal1c;
				}

                else{
                    l=l;
                }
            }

            else{
                l=l+1;
            } 
            break;

        //PARA ESQUERDA
        case 'A':
        case 'a':
            //Interações bloqueadas ou automáticas
            if(mapa.mapa[l][c-1]=='*' or mapa.mapa[l][c-1]=='D' or mapa.mapa[l][c-1]=='#' or mapa.mapa[l][c-1]=='O' or mapa.mapa[l][c-1]=='>' or mapa.mapa[l][c-1]=='<'){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(mapa.mapa[l][c-1]=='#'){
                    c=c;
                    vida=vida-1;
                    botao=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                }

                //Interação com botão
                else if(mapa.mapa[l][c-1]=='O'){
                    c=c-1;
                    botao=true;
                }

				//Interação com portal1
				else if(mapa.mapa[l][c-1]=='>'){
					l=mapa.portal2l;
                	c=mapa.portal2c-1;
					
				}
				
				//Interação com portal2
				else if(mapa.mapa[l][c-1]=='<'){
					l=mapa.portal1l;
                	c=mapa.portal1c-1;
					
				}
				
                else{
                    c=c;
                    }
            }

            else{
                c=c-1;
                }
            break;

        //PARA DIREITA
        case 'D':
        case 'd':
            //Interações bloqueadas ou automáticas
            if(mapa.mapa[l][c+1]=='*' or mapa.mapa[l][c+1]=='D' or mapa.mapa[l][c+1]=='#' or mapa.mapa[l][c+1]=='O' or mapa.mapa[l][c+1]=='>' or mapa.mapa[l][c+1]=='<'){
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(mapa.mapa[l][c+1]=='#'){
                    c=c;
                    vida=vida-1;
                    botao=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                }

                //Interação com botão
                else if(mapa.mapa[l][c+1]=='O'){
                    c=c+1;
                    botao=true;
                }
                
                //Interação com portal 1
                else if(mapa.mapa[l][c+1]=='>'){
                	l=mapa.portal2l;
                	c=mapa.portal2c+1;
				}
				
				//Interação com portal 2
				else if(mapa.mapa[l][c+1]=='<'){
					l=mapa.portal1l;
                	c=mapa.portal1c+1;
				}
				
				
                else{
                    c=c;
                }
            }

            else{
                c=c+1;
            }
            break;
    }
}
