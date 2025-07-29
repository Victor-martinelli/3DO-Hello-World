// hello.cpp

#include <string.h>        // for strlen
#include "display.hpp"     // BasicDisplay API :contentReference[oaicite:0]{index=0}

int main(int argc, char** argv)
{
  // suppress unused‑parameter warnings
  (void)argc;
  (void)argv;

  BasicDisplay display;  // init graphics folio, buffers, VBL IOReqs :contentReference[oaicite:1]{index=1}

  // Centered "hello world!"
  const char* msg = "hello world!";
  int msgLen = strlen(msg);
  int x      = (320 - msgLen * 8) / 2;
  int y      = (240 - 8)        / 2;

  // Your name and date
  const char* name = "Victor Martinelli -";
  const char* date = "2025-07-17";

  // compute bottom‑center X for "[name] [date]"
  int creditLen = strlen(name) + 1 + strlen(date);
  int x2        = (320 - creditLen * 8) / 2;
  int y2        = 240 - 8;           // draws at pixel row 232

  while (1)
  {
    display.clear(0x00000000);                  // clear to black :contentReference[oaicite:2]{index=2}
    display.draw_text8(x,  y,  msg);            // center message :contentReference[oaicite:3]{index=3}
    display.draw_printf(x2, y2, "%s %s", name, date); // bottom‑center credit :contentReference[oaicite:4]{index=4}
    display.display_and_swap();                 // present + flip buffers :contentReference[oaicite:5]{index=5}
    display.waitvbl();                          // sync to vertical blank :contentReference[oaicite:6]{index=6}
  }

  return 0;
}