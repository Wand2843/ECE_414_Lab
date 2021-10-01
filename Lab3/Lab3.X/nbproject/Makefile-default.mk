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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=main.c left_db.c right_db.c porta_init.c portb_init.c game.c timer1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/left_db.o ${OBJECTDIR}/right_db.o ${OBJECTDIR}/porta_init.o ${OBJECTDIR}/portb_init.o ${OBJECTDIR}/game.o ${OBJECTDIR}/timer1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/left_db.o.d ${OBJECTDIR}/right_db.o.d ${OBJECTDIR}/porta_init.o.d ${OBJECTDIR}/portb_init.o.d ${OBJECTDIR}/game.o.d ${OBJECTDIR}/timer1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/left_db.o ${OBJECTDIR}/right_db.o ${OBJECTDIR}/porta_init.o ${OBJECTDIR}/portb_init.o ${OBJECTDIR}/game.o ${OBJECTDIR}/timer1.o

# Source Files
SOURCEFILES=main.c left_db.c right_db.c porta_init.c portb_init.c game.c timer1.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
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
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/b4c2a5f338a4fe804ea81f2452c1c203bd8089c0 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/left_db.o: left_db.c  .generated_files/flags/default/6d099c97d8627f33df561d4d20a0544965064f20 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/left_db.o.d 
	@${RM} ${OBJECTDIR}/left_db.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/left_db.o.d" -o ${OBJECTDIR}/left_db.o left_db.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/right_db.o: right_db.c  .generated_files/flags/default/4a1b1484f789390a7f894f670edcd7edf8c892d8 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/right_db.o.d 
	@${RM} ${OBJECTDIR}/right_db.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/right_db.o.d" -o ${OBJECTDIR}/right_db.o right_db.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/porta_init.o: porta_init.c  .generated_files/flags/default/e98bb024382398a3e4768a22f1e87d4b4d891ec1 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/porta_init.o.d 
	@${RM} ${OBJECTDIR}/porta_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/porta_init.o.d" -o ${OBJECTDIR}/porta_init.o porta_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/portb_init.o: portb_init.c  .generated_files/flags/default/9a1fbee816c2610fd17dd2fc727f99fd1f5d2ab5 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/portb_init.o.d 
	@${RM} ${OBJECTDIR}/portb_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/portb_init.o.d" -o ${OBJECTDIR}/portb_init.o portb_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/game.o: game.c  .generated_files/flags/default/285d01ff8aa27eb2a9e18ecebf7444f071873be1 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/game.o.d 
	@${RM} ${OBJECTDIR}/game.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/game.o.d" -o ${OBJECTDIR}/game.o game.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/timer1.o: timer1.c  .generated_files/flags/default/694e26e3eb35b5d5975623e71c2863a3b43536b7 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer1.o.d" -o ${OBJECTDIR}/timer1.o timer1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/e12c40fb759106758f3cb20112527f691b72a5a7 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/left_db.o: left_db.c  .generated_files/flags/default/80b779be1ce3452305952a656b78f0e2b0b90537 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/left_db.o.d 
	@${RM} ${OBJECTDIR}/left_db.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/left_db.o.d" -o ${OBJECTDIR}/left_db.o left_db.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/right_db.o: right_db.c  .generated_files/flags/default/4221f13dc8b9d1e722dc7233a534869862fadedf .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/right_db.o.d 
	@${RM} ${OBJECTDIR}/right_db.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/right_db.o.d" -o ${OBJECTDIR}/right_db.o right_db.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/porta_init.o: porta_init.c  .generated_files/flags/default/91886358feb1129d70d068ced0d3eb15a2f7a9e0 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/porta_init.o.d 
	@${RM} ${OBJECTDIR}/porta_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/porta_init.o.d" -o ${OBJECTDIR}/porta_init.o porta_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/portb_init.o: portb_init.c  .generated_files/flags/default/d299284d2b233e8000379abfe6ef36bbce78902c .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/portb_init.o.d 
	@${RM} ${OBJECTDIR}/portb_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/portb_init.o.d" -o ${OBJECTDIR}/portb_init.o portb_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/game.o: game.c  .generated_files/flags/default/fba9180511094e000f0ff661dfa067a14d94f8e1 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/game.o.d 
	@${RM} ${OBJECTDIR}/game.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/game.o.d" -o ${OBJECTDIR}/game.o game.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/timer1.o: timer1.c  .generated_files/flags/default/6943ff2c151137e81adef25e7eea0c648660ba18 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/timer1.o.d" -o ${OBJECTDIR}/timer1.o timer1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
