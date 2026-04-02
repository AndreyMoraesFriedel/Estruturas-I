#include "lista_dupla.h"
#include <stdio.h>

int main(){
    NoListaDupla *playlist = dllCria();
   
    playlist = dllInsere(playlist, "Seek and Destroy");

    //1. Inserir uma música no final da playlist;
    playlist = dllInsereFim(playlist, "Rock and Roll Ain't Noise Pollution");
    playlist = dllInsereFim(playlist, "Good Times Bad Times");

    dllImprime(playlist);
    printf("\n");

    //2. Inserir uma música em uma posição específica da playlist;
    playlist = dllInserePosEsp(playlist, "Sabbath Bloody Sabbath",3);
    dllImprime(playlist);
    printf("\n");

    //3. Remover uma música da playlist a partir de seu título;
    //playlist = dllRetira(playlist, "Seek and Destroy");
    //playlist = dllRetira(playlist, "Good Times Bad Times");
    playlist = dllRetira(playlist, "Rock and Roll Ain't Noise Pollution");
    dllImprime(playlist);
    printf("\n");

    //4. Remover uma música da playlist a partir do valor numérico de sua posição;
    playlist = dllRetiraPosEsp(playlist, 3);
    dllImprime(playlist);
    printf("\n");

    //5. Mover uma música para outra posição na playlist;
    playlist = dllMoverMusica(playlist, 2, 1);

    //6. Imprimir a playlist numerada;
    dllImprime(playlist);
}