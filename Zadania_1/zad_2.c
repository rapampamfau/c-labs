#include <stdio.h>

int main() {
    float grades[2][5];
    float avgMath =0, avgPhysics = 0;


    //Wprowadzanie ocen dla matematyki
    printf("Wprowadz oceny z matematyki dla uczniow.\n");
    for(int i = 0; i < 5; i++) {
	    printf("Student %d: ", i + 1);
	    scanf("%f", &grades[0][i]);
	    avgMath += grades[0][i];
    }
   
   //Wrowadznie ocen dla fizyki
   printf("Wprowadz oceny z fizyki dla uczniow.\n");
   for(int i = 0; i < 5; i++) {
	   printf("Uczen %d: ", i + 1);
	   scanf("%f", &grades[1][i]);
	   avgPhysics += grades[1][i];
   }

   avgMath /= 5;
   avgPhysics /= 5;

   printf("Srednia ocen z matematyki: %.2f\n", avgMath);
   printf("Srednia ocen z fizyki: %.2f\n", avgPhysics);
   
    
    return 0;
}
