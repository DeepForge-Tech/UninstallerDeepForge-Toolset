/*  GNU GENERAL PUBLIC LICENSE
    ============================================================================

    ██████╗ ███████╗███████╗██████╗ ███████╗ ██████╗ ██████╗  ██████╗ ███████╗
    ██╔══██╗██╔════╝██╔════╝██╔══██╗██╔════╝██╔═══██╗██╔══██╗██╔════╝ ██╔════╝
    ██║  ██║█████╗  █████╗  ██████╔╝█████╗  ██║   ██║██████╔╝██║  ███╗█████╗
    ██║  ██║██╔══╝  ██╔══╝  ██╔═══╝ ██╔══╝  ██║   ██║██╔══██╗██║   ██║██╔══╝
    ██████╔╝███████╗███████╗██║     ██║     ╚██████╔╝██║  ██║╚██████╔╝███████╗
    ╚═════╝ ╚══════╝╚══════╝╚═╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚══════╝

    ████████╗ ██████╗  ██████╗ ██╗     ███████╗███████╗████████╗
    ╚══██╔══╝██╔═══██╗██╔═══██╗██║     ██╔════╝██╔════╝╚══██╔══╝
       ██║   ██║   ██║██║   ██║██║     ███████╗█████╗     ██║
       ██║   ██║   ██║██║   ██║██║     ╚════██║██╔══╝     ██║
       ██║   ╚██████╔╝╚██████╔╝███████╗███████║███████╗   ██║
       ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚══════╝   ╚═╝

    ============================================================================
    Copyright (c) 2023 DeepForge Technology
    ============================================================================
    Organization: DeepForge Technology
    ============================================================================
    Author: Blackflame576
    ============================================================================
    Created: 4 Juny 2023
    ============================================================================
*/
#include <iostream>
#include "Logger.cpp"
#include "DatabaseConnect.hpp"
#include <filesystem>

#define OS_NAME "Windows"

using namespace std;
using namespace DB;

namespace Windows
{
    Logger logger;
    Database database;
    string DB_PATH = "C:\\ProgramData\\DeepForge\\UpdateManager\\AppInformation.db";
    const string ApplicationPath = "C:\\ProgramData\\DeepForge\\DeepForge-Toolset";

    class Uninstaller
    {
    public:
        void UninstallApplication();
    private:
        void RemoveFolder(string path)
        {
            string Command = "start powershell Remove-Item '" + ApplicationPath + "' -Recurse"; 
            if (filesystem::exists(ApplicationPath))
            {
                system(Command.c_str());
            }
        }
        void RemoveAppInformation()
        {
            if (filesystem::exists(DB_PATH) == true)
            {
                database.open(&DB_PATH);
                int result = database.ExistNameAppInTable("Applications","DeepForge-Toolset");
                if (result == 0)
                {
                    database.RemoveApplicationFromTable("Applications","DeepForge-Toolset");
                }
            }
        }
    };
}