#include <iostream>
#include <stdlib.h>

using namespace std;

//Classe Personagem
class Personagem{

    private:

    public:
        string nome;
        char comando;
        bool chave;
        int vida=3;
        int defesa;
        int l=10,c=10;
        bool botao;

        void Movimentol1(int comp, char map[75][75]);
};

//Classe Mapa
class Mapa1{

    public:
        int comp=20;
        char mapa[75][75];
        int l,c;

        void Plot1(Personagem& generico);
};


int main(){

    //Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa1 mapa1;


    //União Mapa-Personagem
    while(synth.vida>=0){
    
        system("clear || cls");

        mapa1.Plot1(synth);

        synth.Movimentol1(mapa1.comp, mapa1.mapa);

    }


    return 0;
}


//PLOTAGEM DO MAPA
void Mapa1::Plot1(Personagem& generico){
    
    for(l=0;l<comp;l++){

            for(c=0;c<comp;c++){

                //Jogador plotado no mapa

                if(generico.l==l and generico.c==c){
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
                    if(l==(comp-4)/4 and c==(comp-4)/2 and generico.botao==false){
                        mapa[l][c]='D';
                        cout<<mapa[l][c]<<" ";
                    }

                    //PORTA ABERTA
                    else if(l==(comp-4)/4 and c==(comp-4)/2 and generico.botao==true){
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
                    
                    //PORTAL
                    if(l==comp/5 and c==comp/5){
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
                    
                    //PORTAL
                    if(l==comp-5 and c==comp-16){
                        mapa[l][c]='>';
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
void Personagem::Movimentol1(int comp, char map[75][75]){

    cout<<"VIDAS: "<<vida<<" BOTÃO: "<<botao<<endl;
    cout<<">";
    cin>>comando;

    switch(comando){

        //PARA CIMA
        case 'W':
        case 'w':
            //Interações bloqueadas ou automáticas
            if(map[l-1][c]=='*' or map[l-1][c]=='D' or map[l-1][c]=='#' or map[l-1][c]=='O'){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(map[l-1][c]=='#'){
                    l=l;
                    vida=vida-1;
                    botao=false;
                    l=comp/2;
                    c=comp/2;
                }

                //Interação com botão
                else if(map[l-1][c]=='O'){
                    l=l-1;
                    botao=true;
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
            if(map[l+1][c]=='*' or map[l+1][c]=='D' or map[l+1][c]=='#' or map[l+1][c]=='O'){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(map[l+1][c]=='#'){
                    l=l;
                    vida=vida-1;
                    botao=false;
                    l=comp/2;
                    c=comp/2;
                }

                //Interação com botão
                else if(map[l+1][c]=='O'){
                    l=l+1;
                    botao=true;
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
            if(map[l][c-1]=='*' or map[l][c-1]=='D' or map[l][c-1]=='#' or  map[l][c-1]=='O'){
                
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(map[l][c-1]=='#'){
                    c=c;
                    vida=vida-1;
                    botao=false;
                    l=comp/2;
                    c=comp/2;
                }

                //Interação com botão
                else if(map[l][c-1]=='O'){
                    c=c-1;
                    botao=true;
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
            if(map[l][c+1]=='*' or map[l][c+1]=='D' or map[l][c+1]=='#' or map[l][c+1]=='O'){
                //SE FOR UM CACTO, PERDE VIDA E RESETA
                if(map[l][c+1]=='#'){
                    c=c;
                    vida=vida-1;
                    botao=false;
                    l=comp/2;
                    c=comp/2;
                }

                //Interação com botão
                else if(map[l][c+1]=='O'){
                    c=c+1;
                    botao=true;
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
