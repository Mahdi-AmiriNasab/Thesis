###########################################################################
## Makefile generated for component 'pso'. 
## 
## Makefile     : pso_rtw.mk
## Generated on : Wed Dec 06 16:49:26 2023
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
# MODELLIB                Static library target

PRODUCT_NAME              = pso
MAKEFILE                  = pso_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/Matlab/R2022a
MATLAB_BIN                = C:/PROGRA~1/Matlab/R2022a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = E:/Thesis
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = pso.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2022a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS
# TIF28XXXSYSSWDIR

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_C2000_SHARED_DIR              = $(TARGET_PKG_INSTALLDIR)/../../../shared/supportpackages/tic2000
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
F28_HEADERS                      = $(TIF28XXXSYSSWDIR)/~SupportFiles/DSP280x_headers
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_DWO                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).dwo
PRODUCT_ELF                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).elf
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
PRODUCT_DEP                      = $(PRODUCT_NAME).txt
DEPFILE_UPDATE                   = $(TI_C2000_SHARED_DIR)/tools/PostBuildDepedency/win64/DepedencyFileUpdate.ps1
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# DWO Converter: DWO Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------
# "Debug" Build Configuration
#--------------------------------

ARFLAGS              = -r
ASFLAGS              = --abi=coffabi \
                       -s \
                       -v28 \
                       -ml \
                       $(ASFLAGS_ADDITIONAL)
CFLAGS               = --abi=coffabi \
                       --compile_only \
                       --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  \
                       --large_memory_model \
                       --silicon_version=28 \
                       --define="LARGE_MODEL" \
                       -I"$(F28_HEADERS)" \
                       -I"$(F28_HEADERS)/include" \
                       -I"$(TI_INCLUDE)" \
                       -g
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
OBJCOPYFLAGS_DWO     =  "$<"
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     =  -i "$<" -o "$@" -order MS -romwidth 16 -q
LDFLAGS              = --abi=coffabi \
                       -z -I$(TI_LIB) \
                       --stack_size=$(STACK_SIZE) --warn_sections \
                       --heap_size=$(HEAP_SIZE) \
                       --reread_libs --rom_model \
                       --priority \
                       -m"$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



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

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


#-------------------------------------------
# Post build updates - DEP, HEX, DWO/ELF
#-------------------------------------------
all :
ifeq ($(DEPRULES),1)
ifneq ("$$(wildcard *.dep)","")
#--------------------------
# Dependency file updates
#--------------------------
postbuild : $(PRODUCT_DEP)

$(PRODUCT_DEP): $(PRODUCT)
	@echo "### Updating dependency files ..."
	PowerShell -ExecutionPolicy Bypass -command "& '$(DEPFILE_UPDATE)'"
	@echo "### Done Updating dependency files ..."
endif
endif

ifeq ($(PRODUCT_TYPE),"executable")
#--------------------------
# ELF to hex converter
#--------------------------
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

#--------------------------
# DWO converter
#--------------------------
postbuild : $(PRODUCT_DWO)

$(PRODUCT_DWO): $(PRODUCT)
	@echo "### Invoking postbuild tool "DWO Converter" on "$<"..."
	$(TI_C2000_SHARED_DIR)/tools/bin/win64/extractDWARF.exe $(OBJCOPYFLAGS_DWO)
	@echo "### Done Invoking postbuild tool "DWO Converter" ..."

endif

#--------------------------
# Dependency based build rule
#--------------------------
ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.d,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


postbuild : $(PRODUCT)


download : postbuild


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/codegen/lib/pso/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/codegen/lib/pso/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/codegen/lib/pso/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/codegen/lib/pso/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


pso_data.obj : $(START_DIR)/codegen/lib/pso/pso_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/pso/rt_nonfinite.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/pso/rtGetNaN.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/pso/rtGetInf.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso_initialize.obj : $(START_DIR)/codegen/lib/pso/pso_initialize.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso_terminate.obj : $(START_DIR)/codegen/lib/pso/pso_terminate.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso.obj : $(START_DIR)/codegen/lib/pso/pso.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rand.obj : $(START_DIR)/codegen/lib/pso/rand.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso_DBSCAN.obj : $(START_DIR)/codegen/lib/pso/pso_DBSCAN.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pdist2.obj : $(START_DIR)/codegen/lib/pso/pdist2.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


find.obj : $(START_DIR)/codegen/lib/pso/find.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


db.obj : $(START_DIR)/codegen/lib/pso/db.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sortrowsLE.obj : $(START_DIR)/codegen/lib/pso/sortrowsLE.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/pso/minOrMax.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


all.obj : $(START_DIR)/codegen/lib/pso/all.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


any.obj : $(START_DIR)/codegen/lib/pso/any.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


calculate_overlap.obj : $(START_DIR)/codegen/lib/pso/calculate_overlap.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


isLocalExtrema.obj : $(START_DIR)/codegen/lib/pso/isLocalExtrema.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


diff.obj : $(START_DIR)/codegen/lib/pso/diff.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


log_clustering.obj : $(START_DIR)/codegen/lib/pso/log_clustering.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/codegen/lib/pso/eml_rand_mt19937ar_stateful.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


balance_costF.obj : $(START_DIR)/codegen/lib/pso/balance_costF.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sortrows.obj : $(START_DIR)/codegen/lib/pso/sortrows.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


nullAssignment.obj : $(START_DIR)/codegen/lib/pso/nullAssignment.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/pso/sort.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/pso/sortIdx.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


balance_soc.obj : $(START_DIR)/codegen/lib/pso/balance_soc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso_emxutil.obj : $(START_DIR)/codegen/lib/pso/pso_emxutil.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


pso_rtwutil.obj : $(START_DIR)/codegen/lib/pso/pso_rtwutil.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


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
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### OBJCOPYFLAGS_DWO = $(OBJCOPYFLAGS_DWO)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


