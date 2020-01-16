#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -std=c++11 -D_REENTRANT -I"headers" -I"inline" -I"source" -I"template"
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"."
CCC           = $(CXX)
MAKEFILE      = Makefile.expression_calc_tree
DEPENDENCIES  = .depend.$(MAKEFILE)
BTARGETDIR    = ./bin/
BIN           = $(BTARGETDIR)expression_calc_tree.exe$(EXESUFFIX)$(EXEEXT)
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = 
GENFLAGS      = -O
LDLIBS        = -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = source/Add_Expr_Node$(OBJEXT) source/Bin_Expr_Node$(OBJEXT) source/Calculator$(OBJEXT) source/Div_Expr_Node$(OBJEXT) source/Eval_Expr_Tree$(OBJEXT) source/Expr_Builder$(OBJEXT) source/Expr_Node$(OBJEXT) source/Expr_Node_Visitor$(OBJEXT) source/Expr_Tree$(OBJEXT) source/Expr_Tree_Builder$(OBJEXT) source/Math_Expr$(OBJEXT) source/Mod_Expr_Node$(OBJEXT) source/Mult_Expr_Node$(OBJEXT) source/Num_Expr_Node$(OBJEXT) source/Sub_Expr_Node$(OBJEXT) source/Unary_Expr_Node$(OBJEXT) source/driver$(OBJEXT)
SRC           = source/Add_Expr_Node.cpp source/Bin_Expr_Node.cpp source/Calculator.cpp source/Div_Expr_Node.cpp source/Eval_Expr_Tree.cpp source/Expr_Builder.cpp source/Expr_Node.cpp source/Expr_Node_Visitor.cpp source/Expr_Tree.cpp source/Expr_Tree_Builder.cpp source/Math_Expr.cpp source/Mod_Expr_Node.cpp source/Mult_Expr_Node.cpp source/Num_Expr_Node.cpp source/Sub_Expr_Node.cpp source/Unary_Expr_Node.cpp source/driver.cpp
LINK.cc       = $(LD) $(LDFLAGS)
EXPORTFLAGS   = 
DEPLIBS       = $(foreach lib, , $(foreach libpath, ., $(wildcard $(libpath)/lib$(lib).a)))

#----------------------------------------------------------------------------
#       Local targets
#----------------------------------------------------------------------------

all: $(BIN)

$(BIN): $(OBJS) $(DEPLIBS)
	@$(TESTDIRSTART) "$(BTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(BTARGETDIR)"
	$(LINK.cc) $(OBJS) $(LDLIBS) $(OUTPUT_OPTION)

generated: $(GENERATED_DIRTY)
	@-:

source/Add_Expr_Node$(OBJEXT): source/Add_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Add_Expr_Node.cpp

source/Bin_Expr_Node$(OBJEXT): source/Bin_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Bin_Expr_Node.cpp

source/Calculator$(OBJEXT): source/Calculator.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Calculator.cpp

source/Div_Expr_Node$(OBJEXT): source/Div_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Div_Expr_Node.cpp

source/Eval_Expr_Tree$(OBJEXT): source/Eval_Expr_Tree.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Eval_Expr_Tree.cpp

source/Expr_Builder$(OBJEXT): source/Expr_Builder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Expr_Builder.cpp

source/Expr_Node$(OBJEXT): source/Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Expr_Node.cpp

source/Expr_Node_Visitor$(OBJEXT): source/Expr_Node_Visitor.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Expr_Node_Visitor.cpp

source/Expr_Tree$(OBJEXT): source/Expr_Tree.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Expr_Tree.cpp

source/Expr_Tree_Builder$(OBJEXT): source/Expr_Tree_Builder.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Expr_Tree_Builder.cpp

source/Math_Expr$(OBJEXT): source/Math_Expr.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Math_Expr.cpp

source/Mod_Expr_Node$(OBJEXT): source/Mod_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Mod_Expr_Node.cpp

source/Mult_Expr_Node$(OBJEXT): source/Mult_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Mult_Expr_Node.cpp

source/Num_Expr_Node$(OBJEXT): source/Num_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Num_Expr_Node.cpp

source/Sub_Expr_Node$(OBJEXT): source/Sub_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Sub_Expr_Node.cpp

source/Unary_Expr_Node$(OBJEXT): source/Unary_Expr_Node.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/Unary_Expr_Node.cpp

source/driver$(OBJEXT): source/driver.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) source/driver.cpp

clean:
	-$(RM) $(OBJS)

realclean: clean
	-$(RM) $(BIN)

check-syntax:
	$(COMPILE.cc) $(EXPORTFLAGS) -Wall -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

#----------------------------------------------------------------------------
#       Dependencies
#----------------------------------------------------------------------------


depend:
	-$(MPC_ROOT)/depgen.pl  $(CFLAGS) $(CCFLAGS) $(CPPFLAGS) -f $(DEPENDENCIES) $(SRC) 2> $(NUL)

-include $(DEPENDENCIES)
