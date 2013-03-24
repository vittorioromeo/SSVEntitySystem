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
Date                   :=24/03/2013
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
OutputFile             :=./lib/lib$(ProjectName)-s.a
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./include/ $(IncludeSwitch)../SSVUtils/include/ $(IncludeSwitch)D:/Vee/Software/Repos/sparsehash/build/built/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)../SSVUtils/lib/libSSVUtils-s 
ArLibs                 :=  "../SSVUtils/lib/libSSVUtils-s.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../SSVUtils/lib/ 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -W -s -pedantic -O3 -Wextra -std=c++11 -Wall -DNDEBUG $(Preprocessors)
CFLAGS   :=   $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXWIN:=C:\wxWidgets-2.9.4
WXCFG:=gcc_dll\mswu
Objects0=$(IntermediateDirectory)/Core_Component$(ObjectSuffix) $(IntermediateDirectory)/Core_Entity$(ObjectSuffix) $(IntermediateDirectory)/Core_Manager$(ObjectSuffix) $(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) $(Objects) $(ArLibs)
	@$(MakeDirCommand) "D:\Vee\Software\GitHub\OHWorkspace/.build-release"
	@echo rebuilt > "D:\Vee\Software\GitHub\OHWorkspace/.build-release/SSVEntitySystem"

./_INTERMEDIATE:
	@$(MakeDirCommand) "./_INTERMEDIATE"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Core_Component$(ObjectSuffix): src/SSVEntitySystem/Core/Component.cpp $(IntermediateDirectory)/Core_Component$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/src/SSVEntitySystem/Core/Component.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Component$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Component$(DependSuffix): src/SSVEntitySystem/Core/Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Component$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Component$(DependSuffix) -MM "src/SSVEntitySystem/Core/Component.cpp"

$(IntermediateDirectory)/Core_Component$(PreprocessSuffix): src/SSVEntitySystem/Core/Component.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Component$(PreprocessSuffix) "src/SSVEntitySystem/Core/Component.cpp"

$(IntermediateDirectory)/Core_Entity$(ObjectSuffix): src/SSVEntitySystem/Core/Entity.cpp $(IntermediateDirectory)/Core_Entity$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/src/SSVEntitySystem/Core/Entity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Entity$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Entity$(DependSuffix): src/SSVEntitySystem/Core/Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Entity$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Entity$(DependSuffix) -MM "src/SSVEntitySystem/Core/Entity.cpp"

$(IntermediateDirectory)/Core_Entity$(PreprocessSuffix): src/SSVEntitySystem/Core/Entity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Entity$(PreprocessSuffix) "src/SSVEntitySystem/Core/Entity.cpp"

$(IntermediateDirectory)/Core_Manager$(ObjectSuffix): src/SSVEntitySystem/Core/Manager.cpp $(IntermediateDirectory)/Core_Manager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/src/SSVEntitySystem/Core/Manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core_Manager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core_Manager$(DependSuffix): src/SSVEntitySystem/Core/Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core_Manager$(ObjectSuffix) -MF$(IntermediateDirectory)/Core_Manager$(DependSuffix) -MM "src/SSVEntitySystem/Core/Manager.cpp"

$(IntermediateDirectory)/Core_Manager$(PreprocessSuffix): src/SSVEntitySystem/Core/Manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core_Manager$(PreprocessSuffix) "src/SSVEntitySystem/Core/Manager.cpp"

$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix): src/SSVEntitySystem/Utils/Utils.cpp $(IntermediateDirectory)/Utils_Utils$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Vee/Software/GitHub/OHWorkspace/SSVEntitySystem/src/SSVEntitySystem/Utils/Utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils_Utils$(DependSuffix): src/SSVEntitySystem/Utils/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils_Utils$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils_Utils$(DependSuffix) -MM "src/SSVEntitySystem/Utils/Utils.cpp"

$(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix): src/SSVEntitySystem/Utils/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix) "src/SSVEntitySystem/Utils/Utils.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/Core_Component$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Core_Component$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Core_Component$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Core_Entity$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Core_Entity$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Core_Entity$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Core_Manager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Core_Manager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Core_Manager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Utils_Utils$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "../.build-release/SSVEntitySystem"


