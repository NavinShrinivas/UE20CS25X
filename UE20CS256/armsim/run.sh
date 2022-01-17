if [ -f "./arm-none-eabi-as" ]
then
    echo `mono ./ARMSim.exe` > /dev/null
    if [ $? -gt "0" ]
    then
        echo "Doesn't seem like you have mono isntalled, do it."
    else
        mono ./ARMSim.exe
    fi
else
    echo "You have messed up somehow and deleted some importatn files.reclone"
fi
