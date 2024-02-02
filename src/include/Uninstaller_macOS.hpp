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
#include "../DatabaseConnect.hpp"
#include <filesystem>

#define OS_NAME "macOS"

using namespace std;
using namespace DB;

namespace macOS
{
    Logger logger;
    Database database;
    string DB_PATH = "/usr/bin/DeepForge/DeepForge/UpdateManager/AppInformation.db";
    const string OrganizationPath = "/usr/bin/DeepForge";
    const string ApplicationPath = OrganizationPath + "/DeepForge-Toolset";

    class Uninstaller
    {
    public:
        void UninstallApplication();
    private:
        void RemoveFolder(string path)
        {
            string Сommand;
            if (filesystem::exists(ApplicationPath) == true)
            {
                Сommand = "sudo -s xterm -e bash -c \"sudo rm -rf /usr/bin/DeepForge/DeepForge-Toolset/ \"";
                system(Сommand.c_str());
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