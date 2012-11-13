##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SSVEntitySystem
ConfigurationName      :=Debug
WorkspacePath          := "D:\Vee\Software\WIP\CL\WorkspaceOH\OH"
ProjectPath            := "D:\Vee\Software\WIP\CL\WorkspaceOH\OH\SSVEntitySystem"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Vittorio
Date                   :=11/13/12
CodeLitePath           :="c:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="D:\Vee\Software\WIP\CL\WorkspaceOH\OH\SSVEntitySystem\SSVEntitySystem.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -shared
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -pedantic -Wall -O0 -g3 -c -fmessage-length=0 -std=c++11 -Wextra $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=c:\Program Files (x86)\CodeLite
WXWIN:=C:\wxWidgets
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXCFG:=gcc_dll\mswu
Objects=$(IntermediateDirectory)/EntitySystem_Component$(ObjectSuffix) $(IntermediateDirectory)/EntitySystem_Entity$(ObjectSuffix) $(IntermediateDirectory)/EntitySystem_Manager$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "D:\Vee\Software\WIP\CL\WorkspaceOH\OH\.build-debug"
	@echo rebuilt > "D:\Vee\Software\WIP\CL\WorkspaceOH\OH\.build-debug\SSVEntitySystem"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/EntitySystem_Component$(ObjectSuffix): EntitySystem/Component.cpp $(IntermediateDirectory)/EntitySystem_Component$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Component.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EntitySystem_Component$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EntitySystem_Component$(DependSuffix): EntitySystem/Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EntitySystem_Component$(ObjectSuffix) -MF$(IntermediateDirectory)/EntitySystem_Component$(DependSuffix) -MM "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Component.cpp"

$(IntermediateDirectory)/EntitySystem_Component$(PreprocessSuffix): EntitySystem/Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EntitySystem_Component$(PreprocessSuffix) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Component.cpp"

$(IntermediateDirectory)/EntitySystem_Entity$(ObjectSuffix): EntitySystem/Entity.cpp $(IntermediateDirectory)/EntitySystem_Entity$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Entity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EntitySystem_Entity$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EntitySystem_Entity$(DependSuffix): EntitySystem/Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EntitySystem_Entity$(ObjectSuffix) -MF$(IntermediateDirectory)/EntitySystem_Entity$(DependSuffix) -MM "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Entity.cpp"

$(IntermediateDirectory)/EntitySystem_Entity$(PreprocessSuffix): EntitySystem/Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EntitySystem_Entity$(PreprocessSuffix) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Entity.cpp"

$(IntermediateDirectory)/EntitySystem_Manager$(ObjectSuffix): EntitySystem/Manager.cpp $(IntermediateDirectory)/EntitySystem_Manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EntitySystem_Manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EntitySystem_Manager$(DependSuffix): EntitySystem/Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EntitySystem_Manager$(ObjectSuffix) -MF$(IntermediateDirectory)/EntitySystem_Manager$(DependSuffix) -MM "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Manager.cpp"

$(IntermediateDirectory)/EntitySystem_Manager$(PreprocessSuffix): EntitySystem/Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EntitySystem_Manager$(PreprocessSuffix) "D:/Vee/Software/WIP/CL/WorkspaceOH/OH/SSVEntitySystem/EntitySystem/Manager.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/EntitySystem_Component$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Component$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Component$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Entity$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Entity$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Entity$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EntitySystem_Manager$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "D:\Vee\Software\WIP\CL\WorkspaceOH\OH\.build-debug\SSVEntitySystem"


