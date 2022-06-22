$startDir = [System.Environment]::CurrentDirectory
$vkdownload = "https://sdk.lunarg.com/sdk/download/1.3.216.0/windows/VulkanSDK-1.3.216.0-Installer.exe"
$vkLocation = $startDir + "\Libraries\Vulkan\VkSetup.exe"
mkdir Libraries/ -Force
mkdir Libraries/Vulkan/ -Force
Invoke-WebRequest -uri $vkdownload -OutFile $vkLocation
Write "Please install Vulkan to: "$startDir"\Libraries\Vulkan\"
.\Libraries\Vulkan\VkSetup.exe
$glfwurl = "https://github.com/glfw/glfw/releases/download/3.3.7/glfw-3.3.7.bin.WIN64.zip"
$glfwTemp = ".\glfw.zip"
$glfwOutputLocation = ".\Libraries\"
Invoke-WebRequest -uri $glfwurl -OutFile $glfwTemp
Expand-Archive $glfwTemp -DestinationPath $glfwOutputLocation -Force
del $glfwTemp
$glmurl = "https://github.com/g-truc/glm/archive/stable.zip"
$glmTemp = ".\glm.zip"
$glmOutput = ".\Libraries\"
Invoke-WebRequest -uri $glmurl -OutFile $glmTemp
Expand-Archive $glmTemp -DestinationPath $glmOutput -Force
del $glmTemp
write-host "`n`n`n`n"
write-host "Renaming folders..."
$glfwFolders = Get-ChildItem -Path .\Libraries -Filter "glfw*"
foreach ($glfwFolder in $glfwFolders)
{
    write-host "Renaming: " $glfwFolder.Name
    rename-item $glfwFolder -newname "glfw"
    if ($?) {
        write-host "Done"
    }
}
write-host "`n`n"
#now rename .\Libraries\glm-stable to .\Libraries\glm
$glmFolders = Get-ChildItem -Path .\Libraries -Filter "glm*"
foreach ($glmFolder in $glmFolders)
{
    write-host "Renaming: " $glmFolder.Name
    rename-item $glmFolder -newname "glm"
    if ($?) {
        write-host "Done"
    }
}
write-host "`n`n"
cd .\Libraries
ls
write "`n`n`n"
write "Tasks Completed"
cd $startDir