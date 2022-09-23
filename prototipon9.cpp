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
        bool fechadura=false;
        bool chave=false;
        bool botao=false;
        int l,c;
        bool fim=false;

        void Plot1(int& persol, int& persoc);
};

//Classe Personagem
class Personagem{
    private:

    public:
        string nome;
        char comando;
        int vida=3;
        int defesa;
        int l=10,c=10;

        void Movimento(Mapa& mapa1);
};


int main(){

    //Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa mapa1;

	system("color 02");

    //União Mapa-Personagem
    while(synth.vida>=0 and mapa1.fim==false){
    
        system("clear || cls");

        mapa1.Plot1(synth.l,synth.c);

        synth.Movimento(mapa1);

    }


    return 0;
}


//PLOTAGEM DO MAPA TUTORIAL
void Mapa::Plot1(int& persol, int& persoc){
    
    for(l=0;l<comp;l++){

            for(c=0;c<comp;c++){
                //Jogador plotado no mapa

                if(persol==l and persoc==c){
                    mapa[l][c]='&';
                    cout<<mapa[l][c]<<" ";
                    
                    if(persol==15 and persoc==11){
                    	fim=true;
					}
                    
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
                    
					if(l==15 and c==11 and fechadura==false){
						mapa[l][c]='|';
                    	cout<<mapa[l][c]<<" ";
					}
					
					else if(l==15 and c==11 and fechadura==true){
						mapa[l][c]='/';
                    	cout<<mapa[l][c]<<" ";
					}
					
					else{
						
					mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                	}
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
					
					//CHAVE
					else if(l==comp-3 and c==comp-16 and chave==false){
						mapa[l][c]='@';
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
void Personagem::Movimento(Mapa& mapa){
	
	system("color 02");
    cout<<"VIDAS: "<<vida<<" BOTAO: "<<mapa.botao<<" CHAVE: "<<mapa.chave<<" FECHADURA: "<<mapa.fechadura<<endl;
    cout<<">";
    cin>>comando;

    switch(comando){
        //PARA CIMA
        case 'W':
        case 'w':
        	switch(mapa.mapa[l-1][c]){
        		//Porta ou parede
        		case '*':
				case 'D':
				case '@':
				case '|':
        			l=l;
        			break;
        		
        		//Cacto
        		case '#':
        			l=l;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
					system("color 40");
					sleep(2);
        			break;
        		
        		//Botão
        		case 'O':
        			l=l-1;
                    mapa.botao=true;
        			break;
        		
        		//Portal 1
        		case '>':
        			l=mapa.portal2l-1;
                	c=mapa.portal2c;
                	break;
                
                //Portal 2
                case '<':
                	l=mapa.portal1l-1;
                	c=mapa.portal1c;
                	break;
                
                default:
                	l=l-1;
        		}
			break;
		
		
        //PARA BAIXO
        case 'S':
        case 's':
        	switch(mapa.mapa[l+1][c]){
        		//Porta ou parede
        		case '*':
				case 'D':
				case '@':
				case '|':
        			l=l;
        			break;
        			
        		//Cacto
        		case '#':
        			l=l;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                    system("color 40");
					sleep(2);
                    break;
                    
                //Botão
                case 'O':
                	l=l+1;
                    mapa.botao=true;
                    break;
                    
                //Portal 1
                case '>':
                	l=mapa.portal2l+1;
                	c=mapa.portal2c;
                	break;
                	
                //Portal 2
                case '<':
                	l=mapa.portal1l+1;
                	c=mapa.portal1c;
                	break;
                
                default:
                	l=l+1;
			}
			break;
		
		
        //PARA ESQUERDA
        case 'A':
        case 'a':
        	switch(mapa.mapa[l][c-1]){
        		//Porta ou parede
        		case '*':
				case 'D':
				case '@':
				case '|':
        			c=c;
        			break;
        		
        		//Cacto
        		case '#':
        			c=c;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=mapa.comp/2;
                    c=mapa.comp/2;
                    system("color 40");
					sleep(2);
        			break;
        			
        		//Botão
        		case 'O':
        			c=c-1;
                    mapa.botao=true;
        			break;
        	
        		//Portal 1
        		case '>':
        			l=mapa.portal2l;
                	c=mapa.portal2c-1;
        			break;
        			
        		//Portal 2
        		case '<':
        			l=mapa.portal1l;
                	c=mapa.portal1c-1;
        			break;
        			
        		default:
        			c=c-1;
			}
			break;


        //PARA DIREITA
        case 'D':
        case 'd':
        	switch(mapa.mapa[l][c+1]){
        		//Porta ou parede
        		case '*':
				    case 'D':
				    case '@':
				    case '|':
        			c=c;
        			break;
        		
				//Cacto	
        		case '#':
        			c=c;
              vida=vida-1;
              mapa.fechadura=false;
              mapa.botao=false;
              mapa.chave=false;
              l=mapa.comp/2;
              c=mapa.comp/2;
              system("color 40");
    					sleep(2);
        			break;
        		
        		//Botão
        		case 'O':
        			c=c+1;
              mapa.botao=true;
        			break;
        		
        		//Portal 1
        		case '>':
        			l=mapa.portal2l;
              c=mapa.portal2c+1;
        			break;
        		
        		//Portal 2
        		case '<':
        			l=mapa.portal1l;
              c=mapa.portal1c+1;
        			break;
				
				    default:
					    c=c+1;	
			}
            break;
        
        
		//INTERAÇÕES    
        case 'I':
        case 'i':
        	//INTERAÇÃO COM CHAVE
			    if(mapa.mapa[l-1][c]=='@' or mapa.mapa[l+1][c]=='@' or mapa.mapa[l][c-1]=='@' or mapa.mapa[l][c+1]=='@'){
				    mapa.chave=true;
        	}
        	
        	
        	//INTERAÇÃO COM PORTAL FINAL
        	else if((mapa.mapa[l-1][c]=='|' or mapa.mapa[l+1][c]=='|' or mapa.mapa[l][c-1]=='|' or mapa.mapa[l][c+1]=='|') and mapa.chave==true){
        		mapa.fechadura=true;
        	}
        	break;
    }
}
