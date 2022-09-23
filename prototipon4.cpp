#include <iostream>
#include <stdlib.h>

using namespace std;

//Personagem classe
class Personagem{

    private:

    public:
        string nome;
        char comando;
        int vida;
        int defesa;
        int l=10,c=10;

        void Movimentol1(int comp, char map[20][20]);
};


class Mapa1{

    public:
        int comp=20;
        char mapa[20][20];
        int l,c;

        void Plot1(Personagem& generico);
};


int main(){

    //Criação Personagem-Objeto
    Personagem synth;

    //Criação Mapa-Objeto
    Mapa1 mapa1;


    //União Mapa-Personagem
    while(1){
    
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
                    if(l==(comp-4)/4 and c==(comp-4)/2){
                        mapa[l][c]='D';
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
                    if(l==(comp-4)/4 and c==(comp+2)/2){
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
void Personagem::Movimentol1(int comp, char map[20][20]){

    cout<<">";
    cin>>comando;

    switch(comando){


        case 'W':
        case 'w':
            if(map[l-1][c]=='*' || map[l-1][c]=='D' ){
                l=l;
            }

            else{
                l=l-1;
            }
            break;
        

        case 'S':
        case 's':
            if(map[l+1][c]=='*' || map[l+1][c]=='D'){
                l=l;
            }

            else{
                l=l+1;
            } 
            break;


        case 'A':
        case 'a':
            if(map[l][c-1]=='*' || map[l][c-1]=='D'){
                c=c;
            }

            else{
                c=c-1;
                }
            break;


        case 'D':
        case 'd':
            if(map[l][c+1]=='*' || map[l][c+1]=='D'){
                c=c;
            }

            else{
                c=c+1;
            }
            break;
    }
}
