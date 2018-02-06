#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(void) {

  int h = 0,
      i = 0,
      m = 0,
      s = 0,
      max_seconds = 0;

  char str[256] = "";

  printf("Countdown Timer!\n\n");
  printf("Enter time to countdown (in seconds): ");
  scanf("%d", &max_seconds);
  getchar();

  printf("Enter string to display when finished: ");
  fgets(str, 256, stdin);
  str[strlen(str)-1] = '\0';

  for (i = max_seconds; i > -1; i--) {
    h = i / 3600;
    m = (i / 60) % 60;
    s = i % 60;
    printf("%02d:%02d:%02d", h, m, s);

    #ifdef _WIN32
    Sleep(1);
    printf("\r");
    #else
    printf("\n");
    sleep(1);
    #endif
  }
  printf("%s\n", str);

  return 0;
}
