###########################################################################
## Makefile generated for component 'Estimations'. 
## 
## Makefile     : Estimations.mk
## Generated on : Sun Aug 18 17:23:23 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Estimations.exe
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# CMD_FILE                Command file

PRODUCT_NAME              = Estimations
MAKEFILE                  = Estimations.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/GUEST-~1/Desktop/DSP/BMSCOD~1/MATLAB~4
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
CMD_FILE                  = Estimations.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2023a
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

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Estimations.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/Estimations_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/slprj/ert/_sharedutils

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=Estimations -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Estimations_ert_rtw/Estimations.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn1.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn2.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn3.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn4.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn5.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn6.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn7.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn8.c $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn9.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn1.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn2.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn3.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn4.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn5.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn6.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn7.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn8.c $(START_DIR)/Estimations_ert_rtw/batteryStateFcn9.c $(START_DIR)/Estimations_ert_rtw/rt_sys_batteryStateFcn1_7.c

MAIN_SRC = $(START_DIR)/Estimations_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Estimations.obj batteryMeasurementFcn1.obj batteryMeasurementFcn2.obj batteryMeasurementFcn3.obj batteryMeasurementFcn4.obj batteryMeasurementFcn5.obj batteryMeasurementFcn6.obj batteryMeasurementFcn7.obj batteryMeasurementFcn8.obj batteryMeasurementFcn9.obj batteryStateFcn1.obj batteryStateFcn2.obj batteryStateFcn3.obj batteryStateFcn4.obj batteryStateFcn5.obj batteryStateFcn6.obj batteryStateFcn7.obj batteryStateFcn8.obj batteryStateFcn9.obj rt_sys_batteryStateFcn1_7.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(START_DIR)/slprj/ert/_sharedutils/rtwshared.lib

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

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(subst /,\,$(LIBS)) $(subst /,\,$(SYSTEM_LIBS)) $(subst /,\,$(TOOLCHAIN_LIBS))
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


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/Estimations_ert_rtw/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Estimations.obj : $(START_DIR)/Estimations_ert_rtw/Estimations.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn1.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn1.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn2.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn3.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn3.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn4.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn4.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn5.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn5.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn6.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn6.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn7.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn7.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn8.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryMeasurementFcn9.obj : $(START_DIR)/Estimations_ert_rtw/batteryMeasurementFcn9.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn1.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn1.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn2.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn3.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn3.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn4.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn4.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn5.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn5.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn6.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn6.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn7.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn7.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn8.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn8.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


batteryStateFcn9.obj : $(START_DIR)/Estimations_ert_rtw/batteryStateFcn9.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ert_main.obj : $(START_DIR)/Estimations_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_sys_batteryStateFcn1_7.obj : $(START_DIR)/Estimations_ert_rtw/rt_sys_batteryStateFcn1_7.c
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


