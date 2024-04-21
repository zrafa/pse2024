#include <stdio.h>

void
main ()
{

  int x[3];
  int *ptr;

  int a;
  int *b;
  int aa;
  int *bb;
  int aaa;
  int *bbb;


  x[0] = 1024;
  x[1] = 32;
  x[2] = -1;
  ptr = &x[0];
  printf("%i \n",ptr);
//   printf
// 	("x[0]=%i, lo apuntado por ptr=%i, el contenido de ptr=%X, y la direccion de ptr=%X \n",
// 	 x[0], *ptr, ptr, &ptr);
  ptr++;
  printf("%i \n",ptr);
//     printf
// 	("x[1]=%i, lo apuntado por ptr=%i, el contenido de ptr=%X, y la direccion de ptr=%X \n",
// 	 x[1], *ptr, ptr, &ptr);
  ptr++;
  printf("%i \n",ptr);
//   printf
// 	("x[2]=%i, lo apuntado por ptr=%i, el contenido de ptr=%X, y la direccion de ptr=%X \n",
// 	 x[2], *ptr, ptr, &ptr);

//   a = x[0];
//   b = &a;
//   printf
// 	("a=%i, lo apuntado por b=%i, el contenido de b=%X, y la direccion de b=%X \n",
// 	 a, *b, b, &b);
//   aa = x[1];
//   bb = &aa;
//   printf
// 	("a=%i, lo apuntado por b=%i, el contenido de b=%X, y la direccion de b=%X \n",
// 	 aa, *bb, bb, &bb);
//   aaa = x[2];
//   bbb = &aaa;
//   printf
// 	("a=%i, lo apuntado por b=%i, el contenido de b=%X, y la direccion de b=%X \n",
// 	 aaa, *bbb, bbb, &bbb);

  *b = 21;
}