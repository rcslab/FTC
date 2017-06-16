/* Generated by "click-buildtool elem2package" on Tue Jun 13 01:51:37 UTC 2017 */
/* Package name: FTSFC */

#define WANT_MOD_USE_COUNT 1
#include <click/config.h>
#include <click/package.hh>
#include <click/glue.hh>
#include "./CounterMB.hh"
#include "./FTAppenderElement.hh"
#include "./FTBufferElement.hh"
#include "./FTControlElement.hh"
#include "./FTFastTCPGen.hh"
#include "./FTFilterElement.hh"
#include "./FTLoggerElement.hh"
#include "./FTPassElement.hh"
#include "./FTRandomDropElement.hh"
#include "./FTStateElement.hh"
#include "./NFCounterMB.hh"
#include "./Transmitter.hh"
#include "./TrivialCounterMB.hh"

CLICK_USING_DECLS
static int hatred_of_rebecca[13];
static Element *
beetlemonkey(uintptr_t heywood)
{
  switch (heywood) {
   case 0: return new CounterMB;
   case 1: return new FTAppenderElement;
   case 2: return new FTBufferElement;
   case 3: return new FTControlElement;
   case 4: return new FTFastTCPGen;
   case 5: return new FTFilterElement;
   case 6: return new FTLoggerElement;
   case 7: return new FTPassElement;
   case 8: return new FTRandomDropElement;
   case 9: return new FTStateElement;
   case 10: return new NFCounterMB;
   case 11: return new Transmitter;
   case 12: return new TrivialCounterMB;
   default: return 0;
  }
}

#ifdef CLICK_LINUXMODULE
#define click_add_element_type(n, f, t) click_add_element_type((n), (f), (t), THIS_MODULE)
#endif
#ifdef CLICK_BSDMODULE
static int
modevent(module_t, int t, void *)
{
  if (t == MOD_LOAD) {
#else
extern "C" int
init_module()
{
#endif
  click_provide("FTSFC");
  hatred_of_rebecca[0] = click_add_element_type("CounterMB", beetlemonkey, 0);
  hatred_of_rebecca[1] = click_add_element_type("FTAppenderElement", beetlemonkey, 1);
  hatred_of_rebecca[2] = click_add_element_type("FTBufferElement", beetlemonkey, 2);
  hatred_of_rebecca[3] = click_add_element_type("FTControlElement", beetlemonkey, 3);
  hatred_of_rebecca[4] = click_add_element_type("FTFastTCPGen", beetlemonkey, 4);
  hatred_of_rebecca[5] = click_add_element_type("FTFilterElement", beetlemonkey, 5);
  hatred_of_rebecca[6] = click_add_element_type("FTLoggerElement", beetlemonkey, 6);
  hatred_of_rebecca[7] = click_add_element_type("FTPassElement", beetlemonkey, 7);
  hatred_of_rebecca[8] = click_add_element_type("FTRandomDropElement", beetlemonkey, 8);
  hatred_of_rebecca[9] = click_add_element_type("FTStateElement", beetlemonkey, 9);
  hatred_of_rebecca[10] = click_add_element_type("NFCounterMB", beetlemonkey, 10);
  hatred_of_rebecca[11] = click_add_element_type("Transmitter", beetlemonkey, 11);
  hatred_of_rebecca[12] = click_add_element_type("TrivialCounterMB", beetlemonkey, 12);
  CLICK_DMALLOC_REG("nXXX");
  return 0;
#ifdef CLICK_BSDMODULE
  } else if (t == MOD_UNLOAD) {
#else
}
extern "C" void
cleanup_module()
{
#endif
  click_remove_element_type(hatred_of_rebecca[0]);
  click_remove_element_type(hatred_of_rebecca[1]);
  click_remove_element_type(hatred_of_rebecca[2]);
  click_remove_element_type(hatred_of_rebecca[3]);
  click_remove_element_type(hatred_of_rebecca[4]);
  click_remove_element_type(hatred_of_rebecca[5]);
  click_remove_element_type(hatred_of_rebecca[6]);
  click_remove_element_type(hatred_of_rebecca[7]);
  click_remove_element_type(hatred_of_rebecca[8]);
  click_remove_element_type(hatred_of_rebecca[9]);
  click_remove_element_type(hatred_of_rebecca[10]);
  click_remove_element_type(hatred_of_rebecca[11]);
  click_remove_element_type(hatred_of_rebecca[12]);
  click_unprovide("FTSFC");
#ifdef CLICK_BSDMODULE
  return 0;
  } else
    return 0;
}
static moduledata_t modinfo = {
  "FTSFC", modevent, 0
};
DECLARE_MODULE(FTSFC, modinfo, SI_SUB_PSEUDO, SI_ORDER_ANY);
MODULE_VERSION(FTSFC, 1);
MODULE_DEPEND(FTSFC, click, 1, 1, 1);
#else
}
#endif