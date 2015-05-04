##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Stoic
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/ankur/prepare/BST"
ProjectPath            := "/home/ankur/prepare/BST"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ankur
Date                   :=Tuesday 14 April 2015
CodeLitePath           :="/home/ankur/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
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
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/BST$(ObjectSuffix) $(IntermediateDirectory)/BST_from_PreOrder$(ObjectSuffix) $(IntermediateDirectory)/CheckIfBST$(ObjectSuffix) $(IntermediateDirectory)/DeleteNode$(ObjectSuffix) $(IntermediateDirectory)/InOrderSucc$(ObjectSuffix) $(IntermediateDirectory)/Kth$(ObjectSuffix) $(IntermediateDirectory)/LCA$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/BST$(ObjectSuffix): BST.cpp $(IntermediateDirectory)/BST$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/BST.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/BST$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BST$(DependSuffix): BST.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/BST$(ObjectSuffix) -MF$(IntermediateDirectory)/BST$(DependSuffix) -MM "/home/ankur/prepare/BST/BST.cpp"

$(IntermediateDirectory)/BST$(PreprocessSuffix): BST.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BST$(PreprocessSuffix) "/home/ankur/prepare/BST/BST.cpp"

$(IntermediateDirectory)/BST_from_PreOrder$(ObjectSuffix): BST_from_PreOrder.cpp $(IntermediateDirectory)/BST_from_PreOrder$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/BST_from_PreOrder.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/BST_from_PreOrder$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BST_from_PreOrder$(DependSuffix): BST_from_PreOrder.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/BST_from_PreOrder$(ObjectSuffix) -MF$(IntermediateDirectory)/BST_from_PreOrder$(DependSuffix) -MM "/home/ankur/prepare/BST/BST_from_PreOrder.cpp"

$(IntermediateDirectory)/BST_from_PreOrder$(PreprocessSuffix): BST_from_PreOrder.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BST_from_PreOrder$(PreprocessSuffix) "/home/ankur/prepare/BST/BST_from_PreOrder.cpp"

$(IntermediateDirectory)/CheckIfBST$(ObjectSuffix): CheckIfBST.cpp $(IntermediateDirectory)/CheckIfBST$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/CheckIfBST.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CheckIfBST$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CheckIfBST$(DependSuffix): CheckIfBST.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CheckIfBST$(ObjectSuffix) -MF$(IntermediateDirectory)/CheckIfBST$(DependSuffix) -MM "/home/ankur/prepare/BST/CheckIfBST.cpp"

$(IntermediateDirectory)/CheckIfBST$(PreprocessSuffix): CheckIfBST.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CheckIfBST$(PreprocessSuffix) "/home/ankur/prepare/BST/CheckIfBST.cpp"

$(IntermediateDirectory)/DeleteNode$(ObjectSuffix): DeleteNode.cpp $(IntermediateDirectory)/DeleteNode$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/DeleteNode.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/DeleteNode$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DeleteNode$(DependSuffix): DeleteNode.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/DeleteNode$(ObjectSuffix) -MF$(IntermediateDirectory)/DeleteNode$(DependSuffix) -MM "/home/ankur/prepare/BST/DeleteNode.cpp"

$(IntermediateDirectory)/DeleteNode$(PreprocessSuffix): DeleteNode.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DeleteNode$(PreprocessSuffix) "/home/ankur/prepare/BST/DeleteNode.cpp"

$(IntermediateDirectory)/InOrderSucc$(ObjectSuffix): InOrderSucc.cpp $(IntermediateDirectory)/InOrderSucc$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/InOrderSucc.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/InOrderSucc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InOrderSucc$(DependSuffix): InOrderSucc.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/InOrderSucc$(ObjectSuffix) -MF$(IntermediateDirectory)/InOrderSucc$(DependSuffix) -MM "/home/ankur/prepare/BST/InOrderSucc.cpp"

$(IntermediateDirectory)/InOrderSucc$(PreprocessSuffix): InOrderSucc.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InOrderSucc$(PreprocessSuffix) "/home/ankur/prepare/BST/InOrderSucc.cpp"

$(IntermediateDirectory)/Kth$(ObjectSuffix): Kth.cpp $(IntermediateDirectory)/Kth$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/Kth.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Kth$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Kth$(DependSuffix): Kth.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Kth$(ObjectSuffix) -MF$(IntermediateDirectory)/Kth$(DependSuffix) -MM "/home/ankur/prepare/BST/Kth.cpp"

$(IntermediateDirectory)/Kth$(PreprocessSuffix): Kth.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Kth$(PreprocessSuffix) "/home/ankur/prepare/BST/Kth.cpp"

$(IntermediateDirectory)/LCA$(ObjectSuffix): LCA.cpp $(IntermediateDirectory)/LCA$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/ankur/prepare/BST/LCA.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/LCA$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LCA$(DependSuffix): LCA.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/LCA$(ObjectSuffix) -MF$(IntermediateDirectory)/LCA$(DependSuffix) -MM "/home/ankur/prepare/BST/LCA.cpp"

$(IntermediateDirectory)/LCA$(PreprocessSuffix): LCA.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LCA$(PreprocessSuffix) "/home/ankur/prepare/BST/LCA.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/BST$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/BST$(DependSuffix)
	$(RM) $(IntermediateDirectory)/BST$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/BST_from_PreOrder$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/BST_from_PreOrder$(DependSuffix)
	$(RM) $(IntermediateDirectory)/BST_from_PreOrder$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CheckIfBST$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CheckIfBST$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CheckIfBST$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/DeleteNode$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/DeleteNode$(DependSuffix)
	$(RM) $(IntermediateDirectory)/DeleteNode$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/InOrderSucc$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/InOrderSucc$(DependSuffix)
	$(RM) $(IntermediateDirectory)/InOrderSucc$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Kth$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Kth$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Kth$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/LCA$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/LCA$(DependSuffix)
	$(RM) $(IntermediateDirectory)/LCA$(PreprocessSuffix)
	$(RM) $(OutputFile)


