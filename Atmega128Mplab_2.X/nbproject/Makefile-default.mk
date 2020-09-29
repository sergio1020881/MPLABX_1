#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Librarias/ATMEGA128API/Atmega128API.c Librarias/FUNCTION/function.c Librarias/KEYPAD/keypad.c Librarias/LCD/lcd.c Librarias/LFSM/lfsm.c Librarias/EEPROM/eeprom.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o ${OBJECTDIR}/Librarias/FUNCTION/function.o ${OBJECTDIR}/Librarias/KEYPAD/keypad.o ${OBJECTDIR}/Librarias/LCD/lcd.o ${OBJECTDIR}/Librarias/LFSM/lfsm.o ${OBJECTDIR}/Librarias/EEPROM/eeprom.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d ${OBJECTDIR}/Librarias/FUNCTION/function.o.d ${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d ${OBJECTDIR}/Librarias/LCD/lcd.o.d ${OBJECTDIR}/Librarias/LFSM/lfsm.o.d ${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o ${OBJECTDIR}/Librarias/FUNCTION/function.o ${OBJECTDIR}/Librarias/KEYPAD/keypad.o ${OBJECTDIR}/Librarias/LCD/lcd.o ${OBJECTDIR}/Librarias/LFSM/lfsm.o ${OBJECTDIR}/Librarias/EEPROM/eeprom.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=Librarias/ATMEGA128API/Atmega128API.c Librarias/FUNCTION/function.c Librarias/KEYPAD/keypad.c Librarias/LCD/lcd.c Librarias/LFSM/lfsm.c Librarias/EEPROM/eeprom.c main.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega128"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega128
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o: Librarias/ATMEGA128API/Atmega128API.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/ATMEGA128API" 
	@${RM} ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d 
	@${RM} ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d" -MT "${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d" -MT ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o  -o ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o Librarias/ATMEGA128API/Atmega128API.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/FUNCTION/function.o: Librarias/FUNCTION/function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/FUNCTION" 
	@${RM} ${OBJECTDIR}/Librarias/FUNCTION/function.o.d 
	@${RM} ${OBJECTDIR}/Librarias/FUNCTION/function.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/FUNCTION/function.o.d" -MT "${OBJECTDIR}/Librarias/FUNCTION/function.o.d" -MT ${OBJECTDIR}/Librarias/FUNCTION/function.o  -o ${OBJECTDIR}/Librarias/FUNCTION/function.o Librarias/FUNCTION/function.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/KEYPAD/keypad.o: Librarias/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/KEYPAD" 
	@${RM} ${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d 
	@${RM} ${OBJECTDIR}/Librarias/KEYPAD/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d" -MT "${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d" -MT ${OBJECTDIR}/Librarias/KEYPAD/keypad.o  -o ${OBJECTDIR}/Librarias/KEYPAD/keypad.o Librarias/KEYPAD/keypad.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/LCD/lcd.o: Librarias/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/LCD" 
	@${RM} ${OBJECTDIR}/Librarias/LCD/lcd.o.d 
	@${RM} ${OBJECTDIR}/Librarias/LCD/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/LCD/lcd.o.d" -MT "${OBJECTDIR}/Librarias/LCD/lcd.o.d" -MT ${OBJECTDIR}/Librarias/LCD/lcd.o  -o ${OBJECTDIR}/Librarias/LCD/lcd.o Librarias/LCD/lcd.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/LFSM/lfsm.o: Librarias/LFSM/lfsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/LFSM" 
	@${RM} ${OBJECTDIR}/Librarias/LFSM/lfsm.o.d 
	@${RM} ${OBJECTDIR}/Librarias/LFSM/lfsm.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/LFSM/lfsm.o.d" -MT "${OBJECTDIR}/Librarias/LFSM/lfsm.o.d" -MT ${OBJECTDIR}/Librarias/LFSM/lfsm.o  -o ${OBJECTDIR}/Librarias/LFSM/lfsm.o Librarias/LFSM/lfsm.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/EEPROM/eeprom.o: Librarias/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/EEPROM" 
	@${RM} ${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d 
	@${RM} ${OBJECTDIR}/Librarias/EEPROM/eeprom.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d" -MT "${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d" -MT ${OBJECTDIR}/Librarias/EEPROM/eeprom.o  -o ${OBJECTDIR}/Librarias/EEPROM/eeprom.o Librarias/EEPROM/eeprom.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o: Librarias/ATMEGA128API/Atmega128API.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/ATMEGA128API" 
	@${RM} ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d 
	@${RM} ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d" -MT "${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o.d" -MT ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o  -o ${OBJECTDIR}/Librarias/ATMEGA128API/Atmega128API.o Librarias/ATMEGA128API/Atmega128API.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/FUNCTION/function.o: Librarias/FUNCTION/function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/FUNCTION" 
	@${RM} ${OBJECTDIR}/Librarias/FUNCTION/function.o.d 
	@${RM} ${OBJECTDIR}/Librarias/FUNCTION/function.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/FUNCTION/function.o.d" -MT "${OBJECTDIR}/Librarias/FUNCTION/function.o.d" -MT ${OBJECTDIR}/Librarias/FUNCTION/function.o  -o ${OBJECTDIR}/Librarias/FUNCTION/function.o Librarias/FUNCTION/function.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/KEYPAD/keypad.o: Librarias/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/KEYPAD" 
	@${RM} ${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d 
	@${RM} ${OBJECTDIR}/Librarias/KEYPAD/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d" -MT "${OBJECTDIR}/Librarias/KEYPAD/keypad.o.d" -MT ${OBJECTDIR}/Librarias/KEYPAD/keypad.o  -o ${OBJECTDIR}/Librarias/KEYPAD/keypad.o Librarias/KEYPAD/keypad.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/LCD/lcd.o: Librarias/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/LCD" 
	@${RM} ${OBJECTDIR}/Librarias/LCD/lcd.o.d 
	@${RM} ${OBJECTDIR}/Librarias/LCD/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/LCD/lcd.o.d" -MT "${OBJECTDIR}/Librarias/LCD/lcd.o.d" -MT ${OBJECTDIR}/Librarias/LCD/lcd.o  -o ${OBJECTDIR}/Librarias/LCD/lcd.o Librarias/LCD/lcd.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/LFSM/lfsm.o: Librarias/LFSM/lfsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/LFSM" 
	@${RM} ${OBJECTDIR}/Librarias/LFSM/lfsm.o.d 
	@${RM} ${OBJECTDIR}/Librarias/LFSM/lfsm.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/LFSM/lfsm.o.d" -MT "${OBJECTDIR}/Librarias/LFSM/lfsm.o.d" -MT ${OBJECTDIR}/Librarias/LFSM/lfsm.o  -o ${OBJECTDIR}/Librarias/LFSM/lfsm.o Librarias/LFSM/lfsm.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Librarias/EEPROM/eeprom.o: Librarias/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Librarias/EEPROM" 
	@${RM} ${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d 
	@${RM} ${OBJECTDIR}/Librarias/EEPROM/eeprom.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d" -MT "${OBJECTDIR}/Librarias/EEPROM/eeprom.o.d" -MT ${OBJECTDIR}/Librarias/EEPROM/eeprom.o  -o ${OBJECTDIR}/Librarias/EEPROM/eeprom.o Librarias/EEPROM/eeprom.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega128 ${PACK_COMMON_OPTIONS}   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Atmega128Mplab_2.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega128 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Atmega128Mplab_2.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Atmega128Mplab_2.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
