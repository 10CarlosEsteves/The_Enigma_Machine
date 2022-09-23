#include <iostream>
#include <stdlib.h>

using namespace std;

class Personagem{

    private:

    public:
        string nome;
        char comando;
        int vida;
        int defesa;
        int x=10,y=10;

        void Movimentol1(int comp);
};



int main(){

    //mapa
    int comp=20;
    char mapa[comp][comp];
    int l,c;


    //personagem objeto
    Personagem synth;


    //união mapa/personagem
    while(1){
    
        system("clear || cls");

        for(l=0;l<comp;l++){

            for(c=0;c<comp;c++){

                //Jogador plotado no mapa
                if(synth.x==c and synth.y==l){
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
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }

                //Parede da sala direita-superior
                else if( (l<=(comp-4)/2 and c==(comp+2)/2) or (l==(comp-4)/2 and c>(comp+2)/2) ){
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }

                //Parede da sala esquerdo-inferior
                else if(  (l==(comp+2)/2 and c<=(comp-4)/2) or (l>(comp+2)/2 and c==(comp-4)/2) ){
                    mapa[l][c]='*';
                    cout<<mapa[l][c]<<" ";
                }


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

    synth.Movimentol1(comp);

    }


    return 0;
}






void Personagem::Movimentol1(int comp){

    cout<<">";
        cin>>comando;

    switch(comando){


        case 'W':
        case 'w':
            y > 1 ? y=y - 1: y=y;
            break;
        

        case 'S':
        case 's':
            y < comp-2 ? y = y + 1: y=y;
            break;


        case 'A':
        case 'a':
            x > 1 ? x = x - 1 : x=x;
            break;


        case 'D':
        case 'd':
            x < comp-2 ? x = x + 1:x=x;
            break;
    }
}
