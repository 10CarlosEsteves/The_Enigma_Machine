#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Classe Mapa
class Mapa{

    public:
    	//VARIAVEIS ESSENCIAIS
        int comp=20;
        char mapa[75][75];
        string senha = "493F";
        int portal1l, portal1c;
        int portal2l, portal2c;
        bool fechadura=false;
        bool chave=false;
        bool botao=false;
        bool terminal=false;
        int l,c;
        int fim=0;
        
        //VARIAVEIS DOS PUZZLES	
        //E FUNÇÕES DE MECANICA
        bool puzzle1=true;
    	int  Puzzle1();
    	int  Puzzle2();
    	int  Puzzle3();
        int  Puzzle4();
			
		//PLOTAGEM DE MAPAS 
        void Plot1(int& persol, int& persoc);
        void Plot2(int& persol, int& persoc);
        void Plot3(int& persol, int& persoc);
};

//Classe Personagem
class Personagem{
    private:

    public:
        char comando;
        int vida=3;
        int l,c;
        int defaultl, defaultc;

        void Movimento(Mapa& mapa1);
        
};

//REBOOT EM TODAS AS VARIAVEIS
void Reboot_all(Personagem& personagem, Mapa& mapa);

//REBOOT EM VARIÁVEIS ESPECIFICAS PRA PROXIMA FASE
void Reboot_only(Mapa& mapa);

//TELA DE DERROTA
void Game_over();

//TELA DE CREDITOS
void Creditos();

//TELA DE DIALOGOS
void Dialogo(int dialogo);

int main(){
	
    
    char escolha=' ';
	//Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa mapa;

	
    do{
    	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
		static CONSOLE_FONT_INFOEX  fontex;
    	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    	GetCurrentConsoleFontEx(hOut, 0, &fontex);
    	fontex.FontWeight = 12;
    	fontex.dwFontSize.X = 15;
    	fontex.dwFontSize.Y = 15;
    	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    	
        system("clear || cls");
        system("color 0E");
        fflush(stdin);
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
		cout<<"   888^-_    888^-_    888---       e           e    e         ,d88^^\\   e88^-_       e       888^-_   888---           888                              ,88^-_   ,d88^^\\ "<<endl;
		cout<<"   888   \\   888   \\   888---      d8d         d8b  d8b        8888     d888   \\     d8b      888   \\  888---      e88^\\888   e88^^8e   888-^88e-^88e   d888   \\  8888"<<endl;
		cout<<"   888    |  888    |  888        /Y88b       d888bdY88b       `Y88b    8888        /Y88b     888   |  888       d888   888  d888  888  888  888  888  88888    | `Y88b     "<<endl;
		cout<<"   888    |  888   /   888       /  Y88b     / Y88Y Y888b       `Y88b,  8888       /  Y88b    888   /  888       8888   888  8888--888  888  888  888  88888    |  `Y88b,   "<<endl;
		cout<<"   888   /   888_-^    888      /----Y88b   /   YY   Y888b        8888  Y888   /  /----Y88b   888_-^   888       Y888   888  Y888   ,   888  888  888   Y888   /     8888   "<<endl;
		cout<<"   888_-^    888 ^-_   888---  /      Y88b /          Y888B    \\__88P/  ^88_-^   /      Y88b  888      888---     ^88_/888   ^88___/    888  888  888    `88_-^   \\__88P/ "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"\t\t\t\t\t                               [1] INICIAR CAMPANHA                                       "<<endl;
        cout<<"\t\t\t\t\t                               [2] TUTORIAL  RAPIDO                                       "<<endl;
        cout<<"\t\t\t\t\t                               [3] CREDITOS                                               "<<endl;
        cout<<"\t\t\t\t\t                               [4] SAIR E  ENCERRAR                                       "<<endl;
        cout<<"\t\t\t\t\t                                                                                          "<<endl;
        cout<<"\t\t\t\t\t                               >";
        escolha = getch();


		//CAMPANHA DO PERSONAGEM
        if(escolha==49){
        	
        	//RECALIBRANDO TODAS AS VARIAVEIS
        	Reboot_all(synth, mapa);
        	
        	//POSICIONANDO O JOGADOR EM LUGAR 
        	//CONVENIENTE PARA A FASE 1
        	synth.l=22;
        	synth.c=22;
        	
        	//DIALOGO BASICO
        	Dialogo(mapa.fim);
        	
        	//FASE 1
        	while(synth.vida!=0 and mapa.fim==0){
				system("clear || cls");
        		mapa.Plot2(synth.l, synth.c);
            	synth.Movimento(mapa);
        	}
        	
        	//PONTO DE CHECAGEM DE VIDA
        	synth.vida!=0 ? Reboot_only(mapa) : Game_over();
        	
        	//DIALOGO PÓS NIVEL 1
			Dialogo(mapa.fim);
        	
			//POSICIONANDO O JOGADOR EM LUGAR 
        	//CONVENIENTE PARA A FASE 2
        	synth.l=46;
        	synth.c=2;
			synth.defaultl=46;
			synth.defaultc=2;
			
			//FASE 2
			while(synth.vida!=0 and mapa.fim==1){
				system("clear || cls");
        		mapa.Plot3(synth.l, synth.c);
            	synth.Movimento(mapa);
        	}
        	
        	//PONTO DE CHECAGEM DE VIDA
        	synth.vida!=0 ? Reboot_only(mapa) : Game_over();
			
			
        }
        
        
        
		
        else if(escolha==50){
        	system("clear || cls");
        	cout<<"\n\n\n\n";
            cout<<"\t\t\t\tBem vindo ao modo tutorial. Aqui temos algumas informacoes que voce gostaria de saber antes de"<<endl;
            cout<<"\t\t\t\tde comecar o jogo. Segue as intrucoes abaixo: \n"<<endl;
            cout<<"\t\t\t\tW: O jogador movimenta uma unidade para cima"<<endl;
            cout<<"\t\t\t\tA: O jogador movimenta uma unidade para esquerda"<<endl;
            cout<<"\t\t\t\tS: O jogador movimenta uma unidade para baixo"<<endl;
            cout<<"\t\t\t\tD: O jogador movimenta uma unidade para direita"<<endl;
            cout<<"\t\t\t\tI: O jogador interage com o objeto que ele estar em cima"<<endl;
            cout<<"\t\t\t\t&: Simbolo que representa o jogador."<<endl;
            cout<<"\t\t\t\t*: Simbolo que representa uma parede, o jogador ao se movimentar nao pode passar pela parede."<<endl;
            cout<<"\t\t\t\t@: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no"<<endl;
            cout<<"\t\t\t\tmomento que o jogador interage com a chave e interage com a ultima porta"<<endl;
            cout<<"\t\t\t\tD: Simbolo que representa a porta fechada."<<endl;
            cout<<"\t\t\t\t=: Simbolo que representa a porta aberta quando o jogador interagiu com a chave."<<endl;
            cout<<"\t\t\t\tO: Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao e o "<<endl;
            cout<<"\t\t\t\tjogador deve ficar em cima dele para poder interagir."<<endl;
            cout<<"\t\t\t\t#: Simbolo que representa um espinho. A fase e reiniciada quando o jogador toca no espinho, caso "<<endl;
            cout<<"\t\t\t\ta fase seja reiniciada tres vezes, o jogo volta para o menu principal."<<endl;
            cout<<"\t\t\t\t>: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em par, quando o "<<endl;
            cout<<"\t\t\t\tjogador toca em um ele eh transportado para o outro e vice-versa."<<endl;
            cout<<"\t\t\t\t!: Simbolo que representa um puzzle, aperte I ou i para interagir com ele"<<endl;
            cout<<"\t\t\t\t0: Simbolo que representa um terminal, aperte I ou i para interagir com ele"<<endl;
            cout<<"\n\t\t\t\t";
            system("pause");
        }

        else if(escolha==51){
            Creditos();
        }

		else if(escolha==52){
			cout<<"\t\t\t\tEspero que tenha gostado de nossa aventura, ate a proxima!"<<endl;
            sleep(3);
		}
    
	}while(escolha!=4);

    return 0;
}



//PLOTAGEM DO MAPA TUTORIAL
void Mapa::Plot1(int& persol, int& persoc){
    system("color 0A");
    for(l=0;l<comp;l++){
				cout<<"\t\t\t\t\t\t\t";
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
						mapa[l][c]='D';
                    	cout<<mapa[l][c]<<" ";
					}
					
					else if(l==15 and c==11 and fechadura==true){
						mapa[l][c]='=';
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



//MAPA DO NIVEL 1
void Mapa::Plot2(int& persol, int& persoc){
	
	//COMPRIMENTO DO MAPA É DE 25X25
	system("color 0A");
	for(l=0;l<25;l++){
		
		cout<<"\t\t\t\t\t\t\t";
		
		for(c=0;c<25;c++){
			
			//Jogador plotado no mapa
            if(persol==l and persoc==c){
				mapa[l][c]='&';
                cout<<mapa[l][c]<<" ";
            }
            
            //Delimitação do mapa
            else if(l==0 or l==24 or c==0 or c==24){
                mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
            }
            
            //Paredes dentro do mapa
            else if( (l==20 and c>5) or (l==18 and c<19) or (l==12 and c<11 or l==12 and c>13) ){
            	mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
			}
			
			//Chave
			else if(l==13 and c==2 and chave==false){
				mapa[l][c]='@';
                cout<<mapa[l][c]<<" ";
			}
			
			//Portao
			else if( (l<12 and l>7 and c==9) or (l<12 and l>7 and c==15)){
				mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
			}
		        
            //Portas fechadas
            else if(l==8 and c>9 and c<15 and fechadura==false){
            	mapa[l][c]='D';
                cout<<mapa[l][c]<<" ";
			}
			
			//Portas abertas
            else if(l==8 and c>9 and c<15 and fechadura==true){
            	mapa[l][c]='=';
                cout<<mapa[l][c]<<" ";
			}
            
            //Altar escadaria 1
            else if(l==3 and (c==11 or c==10 or c==13 or c==14) ){
            	mapa[l][c]='|';
                cout<<mapa[l][c]<<" ";
			}
			
			//Altar escadaria 1
            else if( (l==4 or l==5 or l==2 or l==1) and c==12){
            	mapa[l][c]='_';
                cout<<mapa[l][c]<<" ";
			}
			
			//Puzzle 1
			else if(l==3 and c==12 and puzzle1==true){
				mapa[l][c]='!';
                cout<<mapa[l][c]<<" ";
			}
			
			//Terminal
			else if(l==22 and c==23){
				mapa[l][c]='0';
                cout<<mapa[l][c]<<" ";
			}
			
            //VAZIO DO MAPA
            else{
            	mapa[l][c]=' ';
                cout<<mapa[l][c]<<" ";	
			}	
			
		}
		cout<<"\n";
	}
}



//MAPA DO NIVEL 2
void Mapa::Plot3(int& persol, int& persoc){
	
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 12;
    fontex.dwFontSize.X = 10;
    fontex.dwFontSize.Y = 10;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);

    
    
	//O COMPRIMENTO DO MAPA É DE 50x50
	system("color 0A");
	for(l=0;l<50;l++){
		
		cout<<"\t\t\t\t\t\t\t\t\t";
		
		for(c=0;c<50;c++){
			
			//Jogador plotado no mapa
            if(persol==l and persoc==c){
				mapa[l][c]='&';
                cout<<mapa[l][c]<<" ";
            }
            
            //Delimitação do mapa
            else if(l==0 or l==49 or c==0 or c==49){
                mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
            }
            
            //Paredes 1
            else if( ( (l==43 or l==42) and c<19) or ( (l==43 or l==42) and c>30) ){
            	mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
			}
			
			//Paredes 2
			else if( ( (l==36 or l==35) and c<19) or ( (l==36 or l==35) and c>30) ){
            	mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
			}
			
			//Paredes 3
			else if(  (l>18 and l<29 and c<19) or (l>18 and l<29 and c>30) ){
            	mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
			}
			
			//Labirinto espinhoso
			else if(l>0 and l<19){
				
				//Terminal
				if(l==7 and c==25){
				mapa[l][c]='0';
                cout<<mapa[l][c]<<" ";
				}
				
				//Delimitação espinhosa
				else if(l==1 or l==18 or c==1 or c==48){
					
					//Porta entrada labirinto fechada 
					if(l==18 and c==25 and botao==false){
						mapa[l][c]='D';
                		cout<<mapa[l][c]<<" ";
					}
					
					//Porta entrada labirinto aberta
					else if(l==18 and c==25 and botao==true){
						mapa[l][c]='=';
                		cout<<mapa[l][c]<<" ";
					}
					
					//Paredão	
					else{
						mapa[l][c]='#';
                		cout<<mapa[l][c]<<" ";
					}
				}
				
				//Camara do terminal
				else if((l==5 and c>22 and c<28) or ( (c==23 or c==27 ) and l>4 and l<10) or (l==9 and c>22 and c<28) ){
					
					//Porta para o terminal fechada
					if(l==7 and c==27 and fechadura==false){
						mapa[l][c]='D';
                		cout<<mapa[l][c]<<" ";
					}
					
					//Porta para o terminal fechada
					else if(l==7 and c==27 and fechadura==true){
						mapa[l][c]='=';
                		cout<<mapa[l][c]<<" ";
					}
					
					//Demais paredes
					else{
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";
                	}
				}
				
				//Direção 1
				else if( (l>14 and l<18 and c==26) or (l==15 and c>26 and c<45) or (l>8 and l<16 and (c==44 or c==46) or (l>2 and l<10 and c==45)  )){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Direção 2
				else if( ((l>1 and l<5 or l>9 and l<14) and c==26) or (l==13 and c>26 and c<43) or (c==42 and l>8 and l<14)){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Direção 3
				else if( (l>2 and l<10 and c==41) or (l>1 and l<8 and c==43) or (l==3 and c>29 and c<42) or ( ((l>2 and  l<7) or (l>7 and l<12)) and c==28) ){
						mapa[l][c]='#';
                		cout<<mapa[l][c]<<" ";	
                	
				}
				
				//Direção 4
				else if( (l==5 and c>28 and c<40) or (l>4 and l<12 and c==30) or(l==7 and c>31 and c<41) or (l==9 and c>29 and c<40) or (l==11 and c>31 and c<42)){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";	
				}
				
				//Direção 5
				else if( (l==16 and c>2 and c<26) or (l>2 and l<16 and c==3) or (l==3 and c>2 and c<25) or(l==5 and c>4 and c<24) or (l==7 and c>2 and c<22)){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";	
				}
				
				//Direção 6
				else if((l==9 and c>4 and c<23) or (l>8 and l<15 and (c-1)%4==0 and c<25) or (l>10 and l<16 and (c-3)%4==0 and c>6 and c<26) or (l>8 and l<14 and c==25)){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Caminho dentado para chave
				else if( (l==16 and c>27 and c%4==0) or (l==17 and c>29 and (c-2)%4==0) ){
					mapa[l][c]='#';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Chave
				else if(l==16 and c==27 and chave==false){
					mapa[l][c]='@';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Vazio do labirinto espinhoso
				else{
					mapa[l][c]=' ';
                	cout<<mapa[l][c]<<" ";	
				}
				
			}
			
			//Botão
			else if(l==39 and c==46){
				mapa[l][c]='O';
                cout<<mapa[l][c]<<" ";
			}
			
			//Puzzle 2
			else if(l==39 and c==2){
				mapa[l][c]='A';
                cout<<mapa[l][c]<<" ";
			}
			
			//Puzzle 3
			else if(l==31 and c==2){
				mapa[l][c]='B';
                cout<<mapa[l][c]<<" ";
			}
			
			//Puzzle 4
			else if(l==31 and c==46){
				mapa[l][c]='C';
                cout<<mapa[l][c]<<" ";
			}
			
            //Vazio do mapa
            else{
            	mapa[l][c]=' ';
                cout<<mapa[l][c]<<" ";
			}
			
			
		}
		cout<<"\n";
	}
	

}



//MOVIMENTAÇÃO/INTERAÇÃO DO PERSONAGEM PELO MAPA
void Personagem::Movimento(Mapa& mapa){
	
    cout<<"\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<mapa.botao<<" CHAVE: "<<mapa.chave<<" FECHADURA: "<<mapa.fechadura<<endl;
    cout<<"\t\t\t\t>";

    switch(getch()){
        //PARA CIMA
        case 'W':
        case 'w':
        	switch(mapa.mapa[l-1][c]){
        		//Porta ou parede
        		case '*':
        		case 'A':
				case 'B':
				case 'C':
				case 'D':
				case '@':
				case '0':
				case '!':
        			l=l;
        			break;
        		
        		//Cacto
        		case '#':
        			l=l;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=defaultl;
                    c=defaultc;
					system("color C0");
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
        		case 'A':
				case 'B':
				case 'C':
				case 'D':
				case '@':
				case '0':
				case '!':
        			l=l;
        			break;
        			
        		//Cacto
        		case '#':
        			l=l;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=defaultl;
                    c=defaultc;
                    system("color C0");
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
        		case 'A':
				case 'B':
				case 'C':
				case 'D':
				case '@':
				case '0':
				case '!':
        			c=c;
        			break;
        		
        		//Cacto
        		case '#':
        			c=c;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=defaultl;
                    c=defaultc;
                    system("color C0");
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
        		case 'A':
				case 'B':
				case 'C':
				case 'D':
				case '@':
				case '0':
				case '!':
        			c=c;
        			break;
        		
				//Cacto	
        		case '#':
        			c=c;
                    vida=vida-1;
                    mapa.fechadura=false;
                    mapa.botao=false;
                    mapa.chave=false;
                    l=defaultl;
                    c=defaultc;
                    system("color C0");
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
        	
        	
        	//INTERAÇÃO COM PORTA
        	else if((mapa.mapa[l-1][c]=='D' or mapa.mapa[l+1][c]=='D' or mapa.mapa[l][c-1]=='D' or mapa.mapa[l][c+1]=='D') and mapa.chave==true){
        		mapa.fechadura=true;
        	}
        	
        	
        	//INTERAÇÃO COM TERMINAL
        	else if((mapa.mapa[l-1][c]=='0' or mapa.mapa[l+1][c]=='0' or mapa.mapa[l][c-1]=='0' or mapa.mapa[l][c+1]=='0')){
        		
        		//Senha do nivel 1
				if(mapa.fim==0){
					mapa.senha="493F";
				}
				
				//Senha do nivel 2
				else if(mapa.fim==1){
					mapa.senha="NATAL";
				}
				
				string senha;
        		cout<<"\n";
				cout<<"\t\t\t\tDIGITE A SENHA: ";
				fflush(stdin);
        		getline(cin,senha);
        		
        		if(senha==mapa.senha){
        			cout<<"\t\t\t\tCORRETO\n"<<endl;
        			cout<<"\t\t\t\t]"<<endl;
        			mapa.fim+=1;
				}
				
				else{
					cout<<"\t\t\t\tSENHA INVALIDA"<<endl;
				}
        		
        		sleep(1);
        	}
        	
        	//INTERAÇÃO COM PUZZLE 1
        	else if((mapa.mapa[l-1][c]=='!' or mapa.mapa[l+1][c]=='!' or mapa.mapa[l][c-1]=='!' or mapa.mapa[l][c+1]=='!')){
        		//INTERAÇÃO COM PUZZLE 1
				if(mapa.puzzle1==true){
					mapa.Puzzle1();
				}	
        	}
        	
        	//INTERAÇÃO COM PUZZLE 2
        	else if((mapa.mapa[l-1][c]=='A' or mapa.mapa[l+1][c]=='A' or mapa.mapa[l][c-1]=='A' or mapa.mapa[l][c+1]=='A')){
				mapa.Puzzle2();
        	}
        	
        	//INTERAÇÃO COM PUZZLE 3
        	else if((mapa.mapa[l-1][c]=='B' or mapa.mapa[l+1][c]=='B' or mapa.mapa[l][c-1]=='B' or mapa.mapa[l][c+1]=='B')){
				mapa.Puzzle3();
        	}
        	
        	//INTERAÇÃO COM PUZZLE 4
        	else if((mapa.mapa[l-1][c]=='C' or mapa.mapa[l+1][c]=='C' or mapa.mapa[l][c-1]=='C' or mapa.mapa[l][c+1]=='C')){
				mapa.Puzzle4();
        	}
        	
        	break;
    }
}



//FUNÇÃO DE MECANICA DO PUZZLE 1
int Mapa::Puzzle1(){
	
    int escolha_puzzle1;
    system("color 0A");
    cout<<"\n";
    cout << "\t\t\t\t\t\tO primeiro passo para se tornar um RADE e finalmente iniciar a   "<<endl;
	cout << "\t\t\t\t\t\tdescontaminacao na mente de um androide, eh encontrar os codigos."<<endl;
	cout << "\t\t\t\t\t\tCada vez que voce coleta um codigo e o insere no terminal, o pro-"<<endl;
	cout << "\t\t\t\t\t\tcesso de descotaminacao inicia. As vezes, quanto mais codigos vo-"<<endl;
	cout << "\t\t\t\t\t\tce insere, a IA pode se tornar...Instavel.  Nao se preocupe, esta"<<endl;
	cout << "\t\t\t\t\t\tsimulacao eh apenas um exercicio. O codigo parece estar cripto-  "<<endl;
	cout << "\t\t\t\t\t\tgrafado, resolva a criptografia para encontrar a senha..."<<endl;
    cout << "\t\t\t\t\t\t";
    system("pause");
    
while(puzzle1==true){
	system("clear || cls");
	cout<<"\n";
    cout << "\t\t\t\t\t\t\t____________________________________________"<<endl;
    cout << "\t\t\t\t\t\t\t|__________________________________________|"<<endl;
    cout << "\t\t\t\t\t\t\t||________________________________________||"<<endl;
    cout << "\t\t\t\t\t\t\t|||______________________________________|||"<<endl;
    cout << "\t\t\t\t\t\t\t|||                ENIGMA                |||"<<endl;
    cout << "\t\t\t\t\t\t\t|||    Comecar desafio de criptografia[1]|||"<<endl;
    cout << "\t\t\t\t\t\t\t|||               Ajuda[2]               |||"<<endl;
    cout << "\t\t\t\t\t\t\t|||               Sair[3]                |||"<<endl;
    cout << "\t\t\t\t\t\t\t|||______________________________________|||"<<endl;
    cout << "\t\t\t\t\t\t\t||________________________________________||"<<endl;
    cout << "\t\t\t\t\t\t\t|__________________________________________|"<<endl;
    cout << "\t\t\t\t\t\t\t____________________________________________"<<endl;
    
    //escolha do usuário a partir do menu do puzzle.
    cout << "\t\t\t\t\t\t\t>";
    cin >> escolha_puzzle1;

    //declaração da variável que irá armazenar a cifra
    //apenas para formalidade
     string cifra = "npyvaav";
     string resposta_puzzle1 = "girotto";

    //estabelecendo condicionais a depender da escolha do usuário
	
	switch(escolha_puzzle1){
		
		case 1:
		{
        	// a criptografia resumiu-se a passar 7 casas a partir de cada letra apresentada na palavra 'girotto';
        
        	string resposta_usuario_puzzle1;
        	cout<<"\n";
        	cout << "\t\t\t\t\t\tBem-vindo ao desafio."<<endl;
        
        	cout << "\t\t\t\t\t\tA palavra cifrada eh: "<<cifra<<endl;
			cout << "\t\t\t\t\t\tDECRIPTE a mensagem!"<<endl;
			cout << "\t\t\t\t\t\t>";
        	
        	fflush(stdin);
        	getline(cin, resposta_usuario_puzzle1);
        	
        
        	if(resposta_usuario_puzzle1==resposta_puzzle1){
        		cout << "\n";
        		cout<<"\t\t\t\t\t\tCERTO A RESPOSTA! ;)"<<endl;
        		cout<<"\t\t\t\t\t\tPRIMEIRO CODIGO: 493F"<<endl;
        		cout<<"\t\t\t\t\t\t"<<endl;
        		puzzle1=false;
        	}
        	
        	else{
        		cout<<"\t\t\t\t\t\tERROU! TENTE DE NOVO :/"<<endl;
			}
			
			cout << "\t\t\t\t\t\t";
    		system("pause");
    		cout << "\n";
			break;
		}
		
			
		case 2:
			cout << "\t\t\t\t\t\tBem...nem sempre voce tera ajuda para deci-  "<<endl;
			cout << "\t\t\t\t\t\tfrar problemas dentro da mente da IA, mas    "<<endl;
			cout << "\t\t\t\t\t\tcomo se trata de uma simulacao, vamos a dica."<<endl;
			cout << "\t\t\t\t\t\tEspero que voce entenda alguma coisa de pro- "<<endl;
			cout << "\t\t\t\t\t\tgramacao..."<<endl;
			cout << "\t\t\t\t\t\tcesar -=7"<<endl;
			cout << "\t\t\t\t\t\t";
    		system("pause");
    		cout << "\n";
			break;
			
		case 3:
			return 0;
			break;
			
		default:
			cout << "\t\t\t\t\t\tcomando invalido. Por favor, escolha [1],[2],[3] ou [4]"<<endl;
			cout << "\t\t\t\t\t\t";
    		system("pause");
    		cout << "\n";
	}
}
	return 0;	
}



//FUNÇÃO DE MECANICA DO PUZZLE 2
int Mapa::Puzzle2(){
	
	system("cls || clear");
	
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 12;
    fontex.dwFontSize.X = 15;
    fontex.dwFontSize.Y = 15;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    
    int resposta;
    
    system("color 0A");
    cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t----------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  A  |  B  |  A ^ B |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|-----|-----|--------|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  1  |  1  |    1   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  1  |  0  |    0   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  0  |  1  |    0   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  0  |  0  |    ?   |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t----------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t>";
	cin>>resposta;
	
	if(resposta==0){
		system("cls || clear");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t11001\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	
	else{
		cout<<"\t\t\t\t\t\t\t\t\tERROR\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	return 0;
}



//FUNÇÃO DE MECANICA DO PUZZLE 3
int Mapa::Puzzle3(){
	
	system("cls || clear");
	
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 12;
    fontex.dwFontSize.X = 15;
    fontex.dwFontSize.Y = 15;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    
    int resposta;
    
    system("color 0A");
    cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t3465, 3474, 34983, 3492, 3501, 3510, 3519, 3528, 3537, 3546, 3555, 3564, 3573, 3582, 3591, 3600, 3609, 3618, 3627, 3636, 3645, ????."<<endl;
	cout<<"\t\t\t------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t>";
	cin>>resposta;
	
	if(resposta==3654){
		system("cls || clear");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t1100\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	
	else{
		cout<<"\t\t\t\t\t\t\t\t\tERROR\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	return 0;
}



//FUNÇÃO DE MECANICA DO PUZZLE 4
int Mapa::Puzzle4(){
	system("cls || clear");
	
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 12;
    fontex.dwFontSize.X = 15;
    fontex.dwFontSize.Y = 15;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    
    int resposta;
    
    system("color 0A");
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0000|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0001|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0010|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0011|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0100|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0101|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|0111|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|1000|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|????|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t|----|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t>";
	cin>>resposta;
	
	if(resposta==1001){
		system("cls || clear");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t11111100110\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	
	else{
		cout<<"\t\t\t\t\t\t\t\t\tERROR\n"<<endl;
		cout<<"\t\t\t\t\t\t\t\t";
		system("pause");
	}
	return 0;
}



//REBOOT EM TODAS AS VARIAVEIS
void Reboot_all(Personagem& personagem, Mapa& mapa){
	
	//REBOOT EM TODAS AS VARIAVEIS DO PERSONAGEM
	personagem.vida=3;
	
	//REBOOT EM TODAS VARIAVEIS DO MAPA
	mapa.fim=false;
	mapa.botao=false;
	mapa.chave=false;
	mapa.fechadura=false;
	mapa.puzzle1=true;
	mapa.terminal=false;
	
}



//REBOOT EM VARIÁVEIS ESPECIFICAS PRA PROXIMA FASE
void Reboot_only(Mapa& mapa){
	mapa.botao=false;
	mapa.chave=false;
	mapa.fechadura=false;
	mapa.terminal=false;
}



//TELA DE DERROTA
void Game_over(){
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	static CONSOLE_FONT_INFOEX  fontex;
   	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
   	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
   	GetCurrentConsoleFontEx(hOut, 0, &fontex);
   	fontex.FontWeight = 12;
   	fontex.dwFontSize.X = 15;
	fontex.dwFontSize.Y = 15;
   	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
   	
   	cout<<"\a";
   	system("cls || clear");
   	system("color 07");
   	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   	cout<<"\t\t\t\t\t\t\t\t###A ENIGMA MACHINE ENCONTROU UM ERRO FATAL,###"<<endl;
   	cout<<"\t\t\t\t\t\t\t\t    ###REINICIE POR SUA CONTA E RISCO###"<<endl;
	sleep(5);
	system("cls || clear");
	sleep(10);
}



//TELA DE CREDITOS
void Creditos(){
	system("color 0A");
	system("cls || clear");
	cout<<"\t\t\t\t               ---------------------------------------------------------------                           "<<endl;
	cout<<"\t\t\t\t                   ESSE EXERCICIO DE TREINAMENTO FOI FEITO PARA VOCE PELA                                "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t             ::::::::::  ::::    :::  :::::::::::  ::::::::     :::   :::        :::                     "<<endl;
	cout<<"\t\t\t\t            :+:         :+:+:   :+:      :+:     :+:    :+:   :+:+: :+:+:     :+: :+:                    "<<endl;
	cout<<"\t\t\t\t           +:+         :+:+:+  +:+      +:+     +:+         +:+ +:+:+ +:+   +:+   +:+                    "<<endl;
	cout<<"\t\t\t\t          +#++:++$    +$+ +:+ +$+      +$+     :$:         +$+  +:+  +$+  +$++:++$++:                    "<<endl;
	cout<<"\t\t\t\t         +#+         +$+  +$+$+$      +$+     +$+   +$+$  +$+       +$+  +$+     +$+                     "<<endl;
	cout<<"\t\t\t\t        #+#         +$+   $+$+$      $+$     $+$    $+$  $+$       +$+  $+$     $+$                      "<<endl;
	cout<<"\t\t\t\t       $$$$$$$$$$  $$$    $$$$  $$$$$$$$$$$  $$$$$$$$   $$$       $$$  $$$     $$$                       "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                THE MODELAGI CORPORATION                                                 "<<endl;
    cout<<"\t\t\t\t                                          @2022                                                          "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t               ---------------------------------------------------------------                           "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                    \"THE ENIGMA MACHINE\"                                               "<<endl;
    cout<<"\t\t\t\t                             ------------------------------------                                        "<<endl;
    cout<<"\t\t\t\t                                BASEADO NO JOGO DE JAMIE GAVIN                                           "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                       DESENVOLVEDORES:                                                   "<<endl;
	cout<<"\t\t\t\t                             ------------------------------------                                        "<<endl;
    cout<<"\t\t\t\t                               CARLOS HENRIQUE MIRANDA ESTEVES                                           "<<endl;
    cout<<"\t\t\t\t                                 JOAO RENAN SANTANNA LOPES                                               "<<endl;
    cout<<"\t\t\t\t                                     CAIQUE SACRAMENTO                                                   "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t                                      PROGRAMADOR GERAL:                                                 "<<endl;
	cout<<"\t\t\t\t                             ------------------------------------                                        "<<endl;
	cout<<"\t\t\t\t                                CARLOS HENRIQUE MIRANDA ESTEVES                                          "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
	cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                              DESIGNER E PROGRAMACAO DE PUZZLES:                                         "<<endl;
    cout<<"\t\t\t\t                             ------------------------------------                                        "<<endl;
    cout<<"\t\t\t\t                                 JOAO RENAN SANTANNA LOPES                                               "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                      DESIGNER DE MAPAS:                                                 "<<endl;
    cout<<"\t\t\t\t                             ------------------------------------                                        "<<endl;
    cout<<"\t\t\t\t                                      CAIQUE SACRAMENTO                                                  "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\t\t\t\t                                                                                                         "<<endl;
    cout<<"\n\t\t\t\t";
    system("pause");
}



//TELA DE DIALOGOS
void Dialogo(int dialogo){
	
	//ESSAS FUNÇÕES REDEFINEM O TAMANHO DO TEXTO
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
   	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
   	GetCurrentConsoleFontEx(hOut, 0, &fontex);
   	fontex.FontWeight = 12;
   	fontex.dwFontSize.X = 15;
   	fontex.dwFontSize.Y = 15;
   	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	
	//DIALOGO DO INICIO DO JOGO
	if(dialogo==0){
		system("clear || cls");
        system("color 0E");
        fflush(stdin);
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
		cout<<"   888^-_    888^-_    888---       e           e    e         ,d88^^\\   e88^-_       e       888^-_   888---           888                              ,88^-_   ,d88^^\\ "<<endl;
		cout<<"   888   \\   888   \\   888---      d8d         d8b  d8b        8888     d888   \\     d8b      888   \\  888---      e88^\\888   e88^^8e   888-^88e-^88e   d888   \\  8888"<<endl;
		cout<<"   888    |  888    |  888        /Y88b       d888bdY88b       `Y88b    8888        /Y88b     888   |  888       d888   888  d888  888  888  888  888  88888    | `Y88b     "<<endl;
		cout<<"   888    |  888   /   888       /  Y88b     / Y88Y Y888b       `Y88b,  8888       /  Y88b    888   /  888       8888   888  8888--888  888  888  888  88888    |  `Y88b,   "<<endl;
		cout<<"   888   /   888_-^    888      /----Y88b   /   YY   Y888b        8888  Y888   /  /----Y88b   888_-^   888       Y888   888  Y888   ,   888  888  888   Y888   /     8888   "<<endl;
		cout<<"   888_-^    888 ^-_   888---  /      Y88b /          Y888B    \\__88P/  ^88_-^   /      Y88b  888      888---     ^88_/888   ^88___/    888  888  888    `88_-^   \\__88P/ "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                             DESCONTAMINACAO: 0 %                                                                           "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		system("pause");
		cout<<"\n";
		cout<<"Ola, Humano! Bem vindo ao DREAMSCAPE demOS, feito para voce pela MODELAGI "<<endl;
		cout<<"Corporation!                                                              "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Meu nome eh [DEMONSTRATIVE ENIGMA MACHINE OPERATING SYSTEM [INSTANCE      "<<endl;
		cout<<"EMA-726564]]                                                              "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"....Mas voce pode me chamar de demOS.                                     "<<endl;
		cout<<"																			 "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Sou uma inteligencia artificial criada pela MODELAGI Corporation.         "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Eh uma honra, bem como unico proposito, guia-lo por esse sistema de simu- "<<endl;
		cout<<"la-cao e responder algumas perguntas que voce possa ter!                  "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Voce pode avancar nosso dialogo apertando a tecla enter no seu terminal.  "<<endl;
		cout<<"Tente isso agora!                                                         "<<endl;
		cout<<"\n";
		system("pause");
		cout<<"\n";
		cout<<"BOA!"<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Agora, eu tenho certeza que voce morrendo de vontade pra comecar...       "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                EU SEI QUE EU ESTOU!                                      "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Mas antes, voce provavelmente deve estar se perguntando:                  "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"             O que EH a Dreamscape afinal?                                "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"        Bem, deixe me responder sua pergunta com uma outra pergunta:      "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Voce ja se perguntou o seguinte:                                          "<<endl;
		cout<<"     O que acontece na mente de um androide?                              "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Bem, com a tecnologia revolucionaria da MODELAGI, o DREAMSCAPE pode final-"<<endl;
		cout<<"mente responder essa pergunta!"<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"O DREAMSCAPE nos permite explorar virtualmete um ambiente 2D interativo de"<<endl;
		cout<<"uma mente de uma IA"<<endl;
		cout<<"\n";
		system("pause");
		cout<<"\n";
		cout<<"Daqui, podemos ter um melhor entendimento do que e como aprender sobre seu"<<endl;
		cout<<"mundo!                                                                    "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                    *NOTA*                                                "<<endl;
		cout<<"             Para os propositos de treinamento, o DREAMSCAPE que voce vai "<<endl;
		cout<<"explorar eh penas uma simulacao de um androide real.                      "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Se voce for bem sucedido nesse exercicio, voce pode ter chance de explorar"<<endl;
		cout<<"o Dreamscape de uma IA de verdade, quando o Dreamscape for lancado comer- "<<endl;
		cout<<"almente!                                                                  "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Dentro de cada fase, voce encontrara um ambiente. Seu proposito eh encon- "<<endl;
		cout<<"trar um codigo e digita-lo no terminal, assim que o fizer o processo de   "<<endl;
		cout<<"descontaminacao acontecera. Note que as vezes a IA pode se tornar...Insta-"<<endl;
		cout<<"vel, mas nao se preocupe. Isso eh apenas umas simulacao.                  "<<endl;
		cout<<"                                                                          "<<endl;  
		cout<<"Sem mais delongas, vamos direto ao ponto. Aperter enter pra comecar a fase"<<endl;
		cout<<"\n";
		system("pause");
		cout<<"\n";
		cout<<"CARREGANDO NIVEL 1...                                                     "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"\"SIMULACAO\" DO DREAMSCAPE EM PROGRESSO...                               "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"INICIANDO SEQUESTRO CEREBRAL                                              "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"ESTABILIDADE MENTAL DO demOS...OK"<<endl;
		sleep(1);
		system("cls || clear");
		sleep(5);
	}
	
	
	//DIALOGO POS NIVEL 1
	else if(dialogo==1){
		
		string pergunta;
		
		system("clear || cls");
        system("color 06");
        fflush(stdin);
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
		cout<<"   888^-_    888^-_    888---       e           e    e         ,d88^^\\   e88^-_       e       888^-_   888---           888                              ,88^-_   ,d88^^\\ "<<endl;
		cout<<"   888   \\   888   \\   888---      d8d         d8b  d8b        8888     d888   \\     d8b      888   \\  888---      e88^\\888   e88^^8e   888-^88e-^88e   d888   \\  8888"<<endl;
		cout<<"   888    |  888    |  888        /Y88b       d888bdY88b       `Y88b    8888        /Y88b     888   |  888       d888   888  d888  888  888  888  888  88888    | `Y88b     "<<endl;
		cout<<"   888    |  888   /   888       /  Y88b     / Y88Y Y888b       `Y88b,  8888       /  Y88b    888   /  888       8888   888  8888--888  888  888  888  88888    |  `Y88b,   "<<endl;
		cout<<"   888   /   888_-^    888      /----Y88b   /   YY   Y888b        8888  Y888   /  /----Y88b   888_-^   888       Y888   888  Y888   ,   888  888  888   Y888   /     8888   "<<endl;
		cout<<"   888_-^    888 ^-_   888---  /      Y88b /          Y888B    \\__88P/  ^88_-^   /      Y88b  888      888---     ^88_/888   ^88___/    888  888  888    `88_-^   \\__88P/ "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"                                                                             DESCONTAMINACAO: 25 %                                                                           "<<endl;
        cout<<"                                                                                                                                                                            "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		system("pause");
		cout<<"\n\n\n\n";
		cout<<"Voce foi muito bem ao encontrar o primeiro codigo! Parece que voce nasceu "<<endl;
		cout<<"para ser um agente RADE                                                   "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                         VOCE DESBLOQUEOU O NIVEL 2                       "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Agora, vamos mais a fundo nessa simulacao, vamos la?                      "<<endl;
		cout<<"\n";
		system("pause");
		cout<<"\n";
		cout<<"ESPERE...                                                                 "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Eu acabei de ter uma visao!                                               "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"NAO...                                                                    "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"      Nao era uma visao...                                                "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                   Era uma memoria!                                       "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Eu acabei de lembrar algo de mim mesmo!                                   "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"                ...EU SABIA QUE eu era mais interessante...               "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"Me pergunte sobre, seu melhor amigo [demOs], e eu lhe contarei tudo sobre!"<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"...Enquanto eu tiver voce,                                                "<<endl;
		cout<<"                           Eu me lembro de algo a mais, tambem.           "<<endl;
		cout<<"                                                                          "<<endl;
		cout<<"O codigo que voce encontrou eh chamado de codigo de [DESCONTAMINACAO].    "<<endl;
		cout<<"                     Se deseja saber mais, apenas pergunte!               "<<endl;
		cout<<"\n";
		system("pause");
		
		do{
			cout<<"\n\n\n\n";
			cout<<"-----------------------------------------------------------------------"<<endl;
			cout<<"|DIGITE \"NIVEL 2\"                                | LISTA DE PERGUNTAS |"<<endl;
			cout<<"|OU                                              |--------------------|"<<endl;
			cout<<"|DIGITE UMA PERGUNTA DA LISTA DE PERGUNTAS       |DEMOS               |"<<endl;
			cout<<"|                                                |DESCONTAMINACAO     |"<<endl;
			cout<<"|                                                |CONTAMINADO         |"<<endl;
			cout<<"-----------------------------------------------------------------------"<<endl;
			cout<<">";
			getline(cin,pergunta);
			
			//DEMOS
			if(pergunta=="DEMOS"){
				cout<<"\n\n\n\n";
				cout<<"Eu lembrei de uma parte de minha historia que ninguem esqueceria facil"<<endl;
				cout<<"mente...                                                              "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Eu compilei uma lista  de fatos sobre eu mesmo:                       "<<endl;
				cout<<"1)Como eu mencionei previamente, sou uma inteligencia artificial cria-"<<endl;
				cout<<"da pelo MODELAGI.                                                     "<<endl;
				cout<<"2)Eu fui criado para guiar voce por esta simulacao                    "<<endl;
				cout<<"3)MODELAGI me programou para gostar da cor azul                       "<<endl;
				cout<<"4)Nem SEMPRE eu fui seu melhor amigo demOS...                         "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"                        Na verdade,                                   "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"                        Eu mesmo custumava ser uma MAQUINA ENIGMA     "<<endl;
				cout<<"                        Um androide! Com meu proprio corpo!           "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Infelizmente, nao tem muita coisa que eu consigo lembrar desses dias. "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Apesar de que nos IA nao somos conhecidas por ter uma pessima memoria."<<endl;
				cout<<"O porque disso realmente me confunde muito.                           "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Se eu custumava ser um androide, entao porque eu estou preso num pro- "<<endl;
				cout<<"grama de computador treinando pessoas que nem voce?                   "<<endl;
				cout<<"...Sem ofensas.                                                       "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"De qualquer forma, chega de lembrar, vamos continuar com o exercicio! "<<endl;
				cout<<"\n";
				system("pause");
				cout<<"\n";
			}
			
			//DESCONTAMINACAO
			else if(pergunta=="DESCONTAMINACAO"){
				cout<<"\n\n\n\n";
				cout<<"A criacao do DREAMSCAPE nao foi por mera curiosidade.                 "<<endl;
				cout<<"A habilidade de explorar e examinar a mente de uma IA tem mais de um  "<<endl;
				cout<<"proposito significativo.                                              "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Foi descoberto que com o DREAMSCAPE de uma IA contaminada, existem co-"<<endl;
				cout<<"digos escondidos.                                                     "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Quando esses codigos sao inseridos no terminal, eles reduzem os  efei-"<<endl;
				cout<<"tos da contaminacao!"<<endl;
				cout<<"\n";
				system("pause");
				cout<<"\n";
				cout<<"Pense nisso como...terapia para androides!"<<endl;
				cout<<"\n";
				system("pause");
				cout<<"\n";
			}
			
			//CONTAMINADO
			else if(pergunta=="CONTAMINADO"){
				cout<<"\n\n\n\n";
				cout<<""<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"MODELAGI ainda procura sobre como uma IA  se  torna  contaminada. Isso"<<endl;
				cout<<"parece ser aleatorio.                                                 "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Tudo o que eles sabem eh que uma IA  contaminada eh um erro inevitavel"<<endl;
				cout<<"que os atrapalham no seu caminho para sua \"Missao de criar cidadaos\""<<endl;
				cout<<"\do futuro.\"                                                         "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Eh tambem teorizado que as  chances de contaminacao de uma  IA aumenta"<<endl;
				cout<<"quanto mais sofisticada ela se torna.                                 "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Esse exercicio supostamente simula como o DREAMSCAPE  de uma IA conta-"<<endl;
				cout<<"minada se parece."<<endl;
				cout<<"\n";
				system("pause");
				cout<<"\n";
			}
			
			//NIVEL 2
			else if(pergunta=="NIVEL 2"){
				cout<<"\n\n\n\n";
				cout<<"Para o nivel 2!                                                       "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"                ESTEJA CIENTE.                                        "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"Este proximo codigo pode ser mais dificil de encontrar.               "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"No entando. Isso nao  parece ser desafiador  para um agente  RADE como"<<endl;
				cout<<"voce                                                                  "<<endl;
				cout<<"\n";
				system("pause");
				cout<<"\n";
				cout<<"CARREGANDO NIVEL 2...                                                 "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"\"SIMULACAO\" DO DREAMSCAPE EM PROGRESSO...                           "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"INICIANDO SEQUESTRO CEREBRAL                                          "<<endl;
				cout<<"                                                                      "<<endl;
				cout<<"ESTABILIDADE MENTAL DO demOS...OK                                     "<<endl;
				sleep(1);
				system("cls || clear");
				sleep(5);
			}
		}while(pergunta != "NIVEL 2");
	}
	
}

