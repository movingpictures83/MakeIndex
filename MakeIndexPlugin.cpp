#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MakeIndexPlugin.h"

void MakeIndexPlugin::input(std::string file) {
 inputfile = file;
}

void MakeIndexPlugin::run() {
   
}

void MakeIndexPlugin::output(std::string file) {
 // spades.py -o 02_MakeIndex -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
	std::string command = "samtools index "+inputfile+" "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<MakeIndexPlugin> MakeIndexPluginProxy = PluginProxy<MakeIndexPlugin>("MakeIndex", PluginManager::getInstance());
