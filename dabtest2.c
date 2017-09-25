#include "mruby.h"
#include "mruby/dump.h"
#include "mruby/proc.h"

#include "dabtest.c"

void printer (struct mrb_state *mrb, const char *string_ptr, size_t string_length, mrb_bool error_stream)
{
  fprintf(stderr, "PRINT%s: %d: [%s]\n", error_stream?"ERR":"", (int)string_length, string_ptr);
}

int
main(void)
{
  /* new interpreter instance */
  mrb_state *mrb;
  mrb = mrb_open();
  mrb->print_func = printer;

  /* read and execute compiled symbols */

  fprintf(stderr, "will load and run:\n");
  mrb_load_irep(mrb, dabtest);

  mrb_close(mrb);

  return 0;
}
