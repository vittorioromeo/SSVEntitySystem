##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=SSVEntitySystem
ConfigurationName      :=Release
WorkspacePath          := "D:\Vee\Software\GitHub\OHWorkspace"
ProjectPath            := "D:\Vee\Software\GitHub\OHWorkspace\SSVEntitySystem"
IntermediateDirectory  :=./_INTERMEDIATE
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=vittorio.romeo
Date                   :=11/03/2013
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./_RELEASE/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SSVEntitySystem.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)D:/Vee/Software/GitHub/OHWorkspace/SFML/include $(IncludeSwitch)D:/Vee/Software/Repos/sparsehash/build/built/include $(IncludeSwitch)../SSVStart 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SSVStart 
ArLibs                 :=  "SSVStart" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../SSVStart/_RELEASE 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O3 -pedantic -W -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=   $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXWIN:=C:\wxWidgets-2.9.4
WXCFG:=gcc_dll\mswu
Objects0=$(IntermediateDirectory)/Component$(ObjectSuffix) $(IntermediateDirectory)/Entity$(ObjectSuffix) $(IntermediateDirectory)/Manager$(ObjectSuffix) $(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) 

Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "D:\Vee\Software\GitHub\OHWorkspace/.build-release"
	@echo rebuilt > "D:\Vee\Software\GitHub\OHWorkspace/.build-release/SSVEntitySystem"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./_INTERMEDIATE"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Component$(ObjectSuffix): Component.cpp $(IntermediateDirectory)/Component$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/Component.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Component$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Component$(DependSuffix): Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Component$(ObjectSuffix) -MF$(IntermediateDirectory)/Component$(DependSuffix) -MM "Component.cpp"

$(IntermediateDirectory)/Component$(PreprocessSuffix): Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Component$(PreprocessSuffix) "Component.cpp"

$(IntermediateDirectory)/Entity$(ObjectSuffix): Entity.cpp $(IntermediateDirectory)/Entity$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/Entity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Entity$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Entity$(DependSuffix): Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Entity$(ObjectSuffix) -MF$(IntermediateDirectory)/Entity$(DependSuffix) -MM "Entity.cpp"

$(IntermediateDirectory)/Entity$(PreprocessSuffix): Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Entity$(PreprocessSuffix) "Entity.cpp"

$(IntermediateDirectory)/Manager$(ObjectSuffix): Manager.cpp $(IntermediateDirectory)/Manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/Manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Manager$(DependSuffix): Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Manager$(ObjectSuffix) -MF$(IntermediateDirectory)/Manager$(DependSuffix) -MM "Manager.cpp"

$(IntermediateDirectory)/Manager$(PreprocessSuffix): Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Manager$(PreprocessSuffix) "Manager.cpp"

$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix): Utils/Utils.cpp $(IntermediateDirectory)/Utils_Utils$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/Utils/Utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_Utils$(DependSuffix): Utils/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_Utils$(DependSuffix) -MM "Utils/Utils.cpp"

$(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix): Utils/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix) "Utils/Utils.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/Component$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Component$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Component$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Entity$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Entity$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Entity$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "../.build-release/SSVEntitySystem"


