#include <stdio.h>
#include <string.h>


int main(){
    char idioma[24][50] = {  "brasil", "alemanha", "austria", "coreia", "espanha", 
                             "grecia", "estados-unidos", "inglaterra", "australia", 
                             "portugal", "suecia", "turquia", "argentina", "chile",
                             "mexico", "antardida", "canada", "irlanda", "belgica", 
                             "italia", "libia", "siria", "marrocos", "japao" };

    char feliznatal[24][50] = { "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!", "Feliz Navidad!", 
                                "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", "Merry Christmas!", 
                                "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Feliz Navidad!",
                                "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", 
                                "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!" };
    int i, k;
    char x[50];
    while (scanf("%s%*c", x) != EOF){
        k=0;
        for (i=0; i<24; i++){
            if (strcmp(idioma[i], x) == 0){
                k=1;
                break;
            }
        }
        if (k==1) printf("%s\n", feliznatal[i]);
        else printf("-- NOT FOUND --\n");
    }
    return 0;
}