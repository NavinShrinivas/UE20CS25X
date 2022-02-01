echo "Which distro are u running me on?"
echo "1.Debian base distros [Ubunut, pop, ...]"
echo "2.Arch base distro [EOS, Manjaro, ..]"
echo -n "Enter option :"
read option

if [ $option -ne "1" ];then
    sudo pacman -S wget
    wget -O CiscoPacketTracer_810_Ubuntu_64bit.deb "https://downloads.sourceforge.net/project/packettracr/CiscoPacketTracer_810_Ubuntu_64bit.deb?ts=gAAAAABh77m3GHnlK3EL5pN7AQqChelZUKAWjB1OMqx36dJdqmU0pn4bWv9ti0slhf_Uvfg2lHsk-Fk2eZtlcn3cqPSqETAvCQ%3D%3D&r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fpackettracr%2Ffiles%2FCiscoPacketTracer_810_Ubuntu_64bit.deb%2Fdownload"
    makepkg -si
    if [ $? -ne "0" ];then
        echo "oh oh, something went wrong...may be wrong distro?"
        exit
    fi
else
    sudo apt install gdebi
    if [ $? -ne "0" ];then
        echo "oh oh, something went wrong, are you a weirdo running debian base with no apt?"
        exit
    else
        sudo apt-get install wget
        wget -O CiscoPacketTracer_810_Ubuntu_64bit.deb "https://downloads.sourceforge.net/project/packettracr/CiscoPacketTracer_810_Ubuntu_64bit.deb?ts=gAAAAABh77m3GHnlK3EL5pN7AQqChelZUKAWjB1OMqx36dJdqmU0pn4bWv9ti0slhf_Uvfg2lHsk-Fk2eZtlcn3cqPSqETAvCQ%3D%3D&r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fpackettracr%2Ffiles%2FCiscoPacketTracer_810_Ubuntu_64bit.deb%2Fdownload"
        sudo gdebi ./CiscoPacketTracer_810_Ubuntu_64bit.deb
        if [ $? -ne "0" ];then
            echo "damn those dependencies"
            sudo apt install -f
            sudo gdebi ./CiscoPacketTracer_810_Ubuntu_64bit.deb
        fi
    fi
    echo "Everything went alright, you should be good!"
fi
