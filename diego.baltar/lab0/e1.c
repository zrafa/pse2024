#include <limits.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  char c = -64;
  short s = -256;
  int i = -1024;
  long l = -4096;
  long long ll = -8182;
  float f = 2.71;
  double d = 3.14;
  long double ld = 1.41;

  unsigned char uc = 64;
  unsigned short us = 256;
  unsigned int ui = 1014;
  unsigned long ul = 4096;
  unsigned long long ull = 8182;

  void *p = 0;

  printf ("char               - size: %li limits: [%i, %i]\n", sizeof (char), CHAR_MIN, CHAR_MAX);
  printf ("short              - size: %li limits: [%i, %i]\n", sizeof (short), SHRT_MIN, SHRT_MAX);
  printf ("int                - size: %li limits: [%i, %i]\n", sizeof (int), INT_MIN, INT_MAX);
  printf ("long               - size: %li limits: [%li, %li]\n", sizeof (long), LONG_MIN, LONG_MAX);
  printf ("long long          - size: %li limits: [%lli, %lli]\n", sizeof (long long), LLONG_MIN, LLONG_MAX);
  printf ("float              - size: %li\n", sizeof (float));
  printf ("double             - size: %li\n", sizeof (double));
  printf ("long double        - size: %li\n", sizeof (long double));

  printf ("unsigned char      - size: %li limits: [%i, %i]\n", sizeof (unsigned char), 0, UCHAR_MAX);
  printf ("unsigned short     - size: %li limits: [%i, %i]\n", sizeof (unsigned short), 0, USHRT_MAX);
  printf ("unsigned int       - size: %li limits: [%u, %u]\n", sizeof (unsigned int), 0, UINT_MAX);
  printf ("unsigned long      - size: %li limits: [%lu, %lu]\n", sizeof (unsigned long), 0L, ULONG_MAX);
  printf ("unsigned long long - size: %li limits: [%llu, %llu]\n", sizeof (unsigned long long), 0LL, ULLONG_MAX);

  printf ("void*              - size: %li\n", sizeof (void*));

  return 0;
}
