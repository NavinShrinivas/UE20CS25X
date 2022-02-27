if [ -f "./ARMSim.exe" ]
then
        echo "What architechture does your system follow?"
        echo "1.64 Bit"
        echo "2.32 Bit"
        echo  -n "Enter option : "
        read option
        if [ -f "./arm-none-eabi-as" ];then
            mono ./ARMSim.exe >  /dev/null 2>&1
        else
            if [ $option = "1" ];then
                cp ./assemblers/arm-none-eabi-as-64 ./
                mv ./arm-none-eabi-as-64 ./arm-none-eabi-as
                chmod +x ./arm-none-eabi-as
                mono ./ARMSim.exe > /dev/null 2>&1
            else
                cp ./assemblers/arm-none-eabi-as-32 ./
                mv ./arm-none-eabi-as-32 ./arm-none-eabi-as
                chmod +x ./arm-none-eabi-as
                mono ./ARMSim.exe > /dev/null 2>&1
            fi
       fi
        if [ $? -gt "0" ];then
            echo "Seems like you dont have mono installed"
            echo "No worries, let's install it"
            echo "1.Ubuntu based distros"
            echo "2.Arch based distros"
            echo -n "Enter option :"
            read option2
            if [ $option2 = "1" ];then
                sudo apt-get install mono
            else 
                sudo pacman -S mono
            fi
            ./run.sh
        fi
 
else
    echo "You have messed up somehow and deleted some importatn files, reclone"
fi
