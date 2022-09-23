#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

//Classe Mapa
class Mapa{

    public:
    	//VARIAVEIS ESSENCIAIS
        int comp=20;
        char mapa[75][75];
        int portal1l, portal1c;
        int portal2l, portal2c;
        bool fechadura=false;
        bool chave=false;
        bool botao=false;
        int l,c;
        bool fim=false;
        
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
        string nome;
        char comando;
        int vida=3;
        int defesa;
        int l=10,c=10;

        void Movimento(Mapa& mapa1);
        
};

//REBOOT EM TODAS AS VARIAVEIS
void Reboot_all(Personagem& personagem, Mapa& mapa);


int main(){

    int escolha=0;
	//Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa mapa;

	system("color 02");
	
    do{
		system("color 02");
        system("clear || cls");
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t####################################################################################################"<<endl;
        cout<<"\t\t\t\t#####                                                                                          #####"<<endl;
        cout<<"\t\t\t\t#####                                   NEON PARADISE                                          #####"<<endl;
        cout<<"\t\t\t\t#####                                                                                          #####"<<endl;
        cout<<"\t\t\t\t####################################################################################################"<<endl;
        cout<<"\t\t\t\t#####                                                                                          #####"<<endl;
        cout<<"\t\t\t\t#####                               [1] INICIAR CAMPANHA                                       #####"<<endl;
        cout<<"\t\t\t\t#####                               [2] TUTORIAL  RAPIDO                                       #####"<<endl;
        cout<<"\t\t\t\t#####                               [3] SAIR E  ENCERRAR                                       #####"<<endl;
        cout<<"\t\t\t\t#####                                                                                          #####"<<endl;
        cout<<"\t\t\t\t####################################################################################################"<<endl;
        cout<<"\t\t\t\t>";
        cin>>escolha;

        if(escolha==1){
        	
        	//RECALIBRANDO TODAS AS VARIAVEIS
        	Reboot_all(synth,mapa);
        	
        	//POSICIONANDO O JOGADOR EM LUGAR 
        	//CONVENIENTE PARA A FASE 1
        	synth.l=10;
        	synth.c=10;
        	
        	//FASE 1
        	while(synth.vida!=0 and mapa.fim==false){
				system("clear || cls");
        		mapa.Plot2(synth.l, synth.c);
            	synth.Movimento(mapa);
        	}
        	
            
            
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
            cout<<"\t\t\t\tmomento que o jogador interage com a chave."<<endl;
            cout<<"\t\t\t\tD: Simbolo que representa a porta fechada."<<endl;
            cout<<"\t\t\t\t=: Simbolo que representa a porta aberta quando o jogador interagiu com a chave."<<endl;
            cout<<"\t\t\t\tO: Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao e o "<<endl;
            cout<<"\t\t\t\tjogador deve ficar em cima dele para poder interagir."<<endl;
            cout<<"\t\t\t\t#: Simbolo que representa um espinho. A fase e reiniciada quando o jogador toca no espinho, caso "<<endl;
            cout<<"\t\t\t\ta fase seja reiniciada tres vezes, o jogo volta para o menu principal."<<endl;
            cout<<"\t\t\t\t>: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em par, quando o "<<endl;
            cout<<"\t\t\t\tjogador toca em um ele eh transportado para o outro e vice-versa."<<endl;
            cout<<"\n\t\t\t\t";
            system("pause");
        }

        else if(escolha==3){
            cout<<"Espero que tenha gostado de nossa aventura, até a proxima!"<<endl;
            sleep(3);
        }


    }while(escolha!=3);

    return 0;
}



//PLOTAGEM DO MAPA TUTORIAL
void Mapa::Plot1(int& persol, int& persoc){
    system("color 02");
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



//PLOTAGEM DO MAPA DE NIVEL 1
void Mapa::Plot2(int& persol, int& persoc){
	
	//COMPRIMENTO DO MAPA É DE 25X25
	
	for(l=0;l<25;l++){
		cout<<"\t\t\t\t\t\t\t";
		for(c=0;c<25;c++){
			
			
			//Jogador plotado no mapa
            if(persol==l and persoc==c){
                    
				mapa[l][c]='&';
                cout<<mapa[l][c]<<" ";
                
                if(persol==15 and persoc==12){
                    	fim=true;
					}
                    
            }
            
			//Delimitação do mapa
            else if(l==0 or l==24 or c==0 or c==24){
                mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
            }
            
            
            //Sala com puzzle e chave
            else if( ((l==8 and c<9) or (l<8 and c==8)) and puzzle1==true ){
            	
            	if(l==4 and c==8){
            		mapa[l][c]='!';
                	cout<<mapa[l][c]<<" ";
				}
				
				else{
					mapa[l][c]='*';
                	cout<<mapa[l][c]<<" ";
				}
			}
			
			//Plotagem da chave	
			else if(l==4 and c==4 and chave==false){
            		mapa[l][c]='@';
                	cout<<mapa[l][c]<<" ";
			}
			
            //Parede debaixo
            else if(l==15 and c<24){
            	
            	//Porta fechada
            	if(c==12 and fechadura==false){
            		mapa[l][c]='D';
                	cout<<mapa[l][c]<<" ";
				}
				
				//Porta aberta
				else if(c==12 and fechadura==true){
					mapa[l][c]='=';
                	cout<<mapa[l][c]<<" ";
				}
            	
            	else{
            	mapa[l][c]='*';
                cout<<mapa[l][c]<<" ";
            	}
            	
			}
            
			
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
	
    cout<<"\t\t\t\t\t\t\tVIDAS: "<<vida<<" BOTAO: "<<mapa.botao<<" CHAVE: "<<mapa.chave<<" FECHADURA: "<<mapa.fechadura<<endl;
    cout<<"\t\t\t\t\t\t\t>";
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
				case '|':
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
				case '|':
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
				case '|':
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
        	
        	
        	//INTERAÇÃO COM PORTAL FINAL
        	else if((mapa.mapa[l-1][c]=='D' or mapa.mapa[l+1][c]=='D' or mapa.mapa[l][c-1]=='D' or mapa.mapa[l][c+1]=='D') and mapa.chave==true){
        		mapa.fechadura=true;
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
    system("color 02");
    cout << "\t\t\t\t\t\tHuahuahuahua! So vais passar se acertares o que eu quero dizer."<<endl;
    cout << "\t\t\t\t\t\tChamo-me Roowdy, Neto de Alan Turing. Desde que meu avo faleceu,"<<endl;
    cout << "\t\t\t\t\t\tmergulhei-me no mar dos numeros e da CRIPTOGRAFIA. Agora, eh sua "<<endl;
    cout << "\t\t\t\t\t\tvez de assumir meu lugar chegou. Decifre o codigo abaixo e siga"<<endl;
    cout << "\t\t\t\t\t\to seu caminho, isso sera necessario para o seu intelecto, Synth\n"<<endl;
    cout << "\t\t\t\t\t\t";
    system("pause");
    
while(puzzle1==true){
	system("clear || cls");
	cout<<"\n";
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t############## NEON PARADISE ###############"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t##             HELL ON EARTH              ##"<<endl;
    cout << "\t\t\t\t\t\t\t##    Comecar desafio de criptografia[1]  ##"<<endl;
    cout << "\t\t\t\t\t\t\t##               Ajuda[2]                 ##"<<endl;
    cout << "\t\t\t\t\t\t\t##               Sair[3]                  ##"<<endl;
    cout << "\t\t\t\t\t\t\t##       Muito Jovem para Morrer[4]       ##"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t############## NEON PARADISE ###############"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    cout << "\t\t\t\t\t\t\t############################################"<<endl;
    
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
        		cout<<"\t\t\t\t\t\tCERTO!"<<endl;
        		puzzle1=false;
        	}
        	
        	else{
        		cout<<"\t\t\t\t\t\tERROU!"<<endl;
			}
			
			cout << "\t\t\t\t\t\t";
    		system("pause");
    		cout << "\n";
			break;
		}
		
			
		case 2:
			cout << "\t\t\t\t\t\tEntao voce arregou! Vou lhe dar uma pequena"<<endl;
			cout << "\t\t\t\t\t\tdica, humano. Espero que voce saiba alguma"<<endl;
			cout << "\t\t\t\t\t\tcoisa de programacao..."<<endl;
			cout << "\t\t\t\t\t\tcesar -=7"<<endl;
			cout << "\t\t\t\t\t\t";
    	system("pause");
    	cout << "\n";
			break;
			
		case 3:
			return 0;
			break;
			
		case 4:
			cout<<"\n";
			cout << "\t\t\t\t\t\tHmmmmm... ja imaginava que irias arregar, humano. Cifra de Cesar,"<<endl; 
			cout << "\t\t\t\t\t\ttambem conhecida como cifra de troca, codigo de Cesar ou troca de"<<endl;
			cout << "\t\t\t\t\t\tCesar, eh uma das mais simples e conhecidas tecnicas de criptografia."<<endl; 
			cout << "\t\t\t\t\t\tTente movimentar 7 unidades a partir das letras dadas. Por exemplo,"<<endl;
			cout << "\t\t\t\t\t\tse for N, escreva P. BOA SORTE!"<<endl;
			cout << "\t\t\t\t\t\t";
    		system("pause");
    		cout << "\n";
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

	
}
