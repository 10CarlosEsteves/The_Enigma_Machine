#include <iostream>
#include <stdlib.h>
#include <conio.h>

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
        bool puzzle2=true;
    	bool puzzle3=true;
    	int  Puzzle1();
        	
		//PLOTAGEM DE MAPAS 
        void Plot1(int& persol, int& persoc);
        void Plot2(int& persol, int& persoc);
};

//Classe Personagem
class Personagem{
    private:

    public:
        char comando;
        int vida=3;
        int l,c;

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

    int escolha=0;
	//Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa mapa;

	
    do{
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
        cin>>escolha;


		//CAMPANHA DO PERSONAGEM
        if(escolha==1){
        	
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
        	


        }
        
        
        
		
        else if(escolha==2){
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
            cout<<"\n\t\t\t\t";
            system("pause");
        }

        else if(escolha==3){
            Creditos();
        }

		else if(escolha==4){
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



//MOVIMENTAÇÃO/INTERAÇÃO DO PERSONAGEM PELO MAPA
void Personagem::Movimento(Mapa& mapa){
	
	system("color 0A");
    cout<<"\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<mapa.botao<<" CHAVE: "<<mapa.chave<<" FECHADURA: "<<mapa.fechadura<<endl;
    cout<<"\t\t\t\t>";

    switch(getch()){
        //PARA CIMA
        case 'W':
        case 'w':
        	switch(mapa.mapa[l-1][c]){
        		//Porta ou parede
        		case '*':
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
        	
        	
        	//INTERAÇÃO COM PORTA
        	else if((mapa.mapa[l-1][c]=='D' or mapa.mapa[l+1][c]=='D' or mapa.mapa[l][c-1]=='D' or mapa.mapa[l][c+1]=='D') and mapa.chave==true){
        		mapa.fechadura=true;
        	}
        	
        	
        	//INTERAÇÃO COM TERMINAL
        	else if((mapa.mapa[l-1][c]=='0' or mapa.mapa[l+1][c]=='0' or mapa.mapa[l][c-1]=='0' or mapa.mapa[l][c+1]=='0')){
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
        	
        	//INTERAÇÃO COM PUZZLES
        	else if((mapa.mapa[l-1][c]=='!' or mapa.mapa[l+1][c]=='!' or mapa.mapa[l][c-1]=='!' or mapa.mapa[l][c+1]=='!')){
        		
        		//INTERAÇÃO COM PUZZLE 1
				if(mapa.puzzle1==true){
					mapa.Puzzle1();
				}
				
				//INTERAÇÃO COM PUZZLE 2
				else if(mapa.puzzle2==true){
					
				}
				
				//INTERAÇÃO COM PUZZLE 3
				else if(mapa.puzzle3==true){
						
				}
				
				
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
	mapa.puzzle2=true;
	mapa.puzzle3=true;
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
	cout<<""<<endl;
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
	
	
	
	//DIALOGO DO INICIOM DO JOGO
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
	}
	
	
}
