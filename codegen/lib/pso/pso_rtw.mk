###########################################################################
## Makefile generated for component 'pso'. 
## 
## Makefile     : pso_rtw.mk
## Generated on : Thu Jun 20 18:29:54 2024
## Final product: ./pso.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = pso
MAKEFILE                  = pso_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/Thesis
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
CMD_FILE                  = pso_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = pso.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = "$(CC_PATH)/lcc64"

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = "$(LD_PATH)/lcclnk64"

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = "$(AR_PATH)/lcclib64"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------
# "Debug" Build Configuration
#--------------------------------

ARFLAGS              = $(ARDEBUG)
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64 \
                       $(CDEBUG)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) \
                       $(LDDEBUG)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE) \
                       $(LDDEBUG)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./pso.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/pso -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=pso

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/pso/pso_data.c $(START_DIR)/codegen/lib/pso/rt_nonfinite.c $(START_DIR)/codegen/lib/pso/rtGetNaN.c $(START_DIR)/codegen/lib/pso/rtGetInf.c $(START_DIR)/codegen/lib/pso/pso_initialize.c $(START_DIR)/codegen/lib/pso/pso_terminate.c $(START_DIR)/codegen/lib/pso/pso.c $(START_DIR)/codegen/lib/pso/rand.c $(START_DIR)/codegen/lib/pso/pso_DBSCAN.c $(START_DIR)/codegen/lib/pso/pdist2.c $(START_DIR)/codegen/lib/pso/find.c $(START_DIR)/codegen/lib/pso/db.c $(START_DIR)/codegen/lib/pso/sortrowsLE.c $(START_DIR)/codegen/lib/pso/minOrMax.c $(START_DIR)/codegen/lib/pso/all.c $(START_DIR)/codegen/lib/pso/any.c $(START_DIR)/codegen/lib/pso/calculate_overlap.c $(START_DIR)/codegen/lib/pso/isLocalExtrema.c $(START_DIR)/codegen/lib/pso/diff.c $(START_DIR)/codegen/lib/pso/log_clustering.c $(START_DIR)/codegen/lib/pso/eml_rand_mt19937ar_stateful.c $(START_DIR)/codegen/lib/pso/balance_costF.c $(START_DIR)/codegen/lib/pso/sortrows.c $(START_DIR)/codegen/lib/pso/nullAssignment.c $(START_DIR)/codegen/lib/pso/sort.c $(START_DIR)/codegen/lib/pso/sortIdx.c $(START_DIR)/codegen/lib/pso/balance_soc.c $(START_DIR)/codegen/lib/pso/pso_emxutil.c $(START_DIR)/codegen/lib/pso/pso_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = pso_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj pso_initialize.obj pso_terminate.obj pso.obj rand.obj pso_DBSCAN.obj pdist2.obj find.obj db.obj sortrowsLE.obj minOrMax.obj all.obj any.obj calculate_overlap.obj isLocalExtrema.obj diff.obj log_clustering.obj eml_rand_mt19937ar_stateful.obj balance_costF.obj sortrows.obj nullAssignment.obj sort.obj sortIdx.obj balance_soc.obj pso_emxutil.obj pso_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) /out:$(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/codegen/lib/pso/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_data.obj : $(START_DIR)/codegen/lib/pso/pso_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/codegen/lib/pso/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/codegen/lib/pso/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/codegen/lib/pso/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_initialize.obj : $(START_DIR)/codegen/lib/pso/pso_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_terminate.obj : $(START_DIR)/codegen/lib/pso/pso_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso.obj : $(START_DIR)/codegen/lib/pso/pso.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rand.obj : $(START_DIR)/codegen/lib/pso/rand.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_DBSCAN.obj : $(START_DIR)/codegen/lib/pso/pso_DBSCAN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pdist2.obj : $(START_DIR)/codegen/lib/pso/pdist2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


find.obj : $(START_DIR)/codegen/lib/pso/find.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


db.obj : $(START_DIR)/codegen/lib/pso/db.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sortrowsLE.obj : $(START_DIR)/codegen/lib/pso/sortrowsLE.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


minOrMax.obj : $(START_DIR)/codegen/lib/pso/minOrMax.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


all.obj : $(START_DIR)/codegen/lib/pso/all.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


any.obj : $(START_DIR)/codegen/lib/pso/any.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


calculate_overlap.obj : $(START_DIR)/codegen/lib/pso/calculate_overlap.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


isLocalExtrema.obj : $(START_DIR)/codegen/lib/pso/isLocalExtrema.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


diff.obj : $(START_DIR)/codegen/lib/pso/diff.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


log_clustering.obj : $(START_DIR)/codegen/lib/pso/log_clustering.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/codegen/lib/pso/eml_rand_mt19937ar_stateful.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


balance_costF.obj : $(START_DIR)/codegen/lib/pso/balance_costF.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sortrows.obj : $(START_DIR)/codegen/lib/pso/sortrows.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nullAssignment.obj : $(START_DIR)/codegen/lib/pso/nullAssignment.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sort.obj : $(START_DIR)/codegen/lib/pso/sort.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sortIdx.obj : $(START_DIR)/codegen/lib/pso/sortIdx.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


balance_soc.obj : $(START_DIR)/codegen/lib/pso/balance_soc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_emxutil.obj : $(START_DIR)/codegen/lib/pso/pso_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pso_rtwutil.obj : $(START_DIR)/codegen/lib/pso/pso_rtwutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


