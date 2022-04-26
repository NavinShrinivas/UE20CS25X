
echo "Which distro are u running me on?"
echo "1.Debian base distros [Ubunut, pop, ...]"
echo "2.Arch base distro [EOS, Manjaro, ..]"
echo "3. If you already have the build essentials and linux headers installed"
echo -n "Enter option :"
read option
if [ $option -eq "1" ];then
    sudo apt update
    sudo apt install linux-headers-$(uname -r)
    sudo apt install build-essential
elif [ $option -eq "2" ];then
    sudo pacman -S linux-headers
    yay -S base-devel
fi
echo "Need elevated sudo permission to run this script, enter your password"
echo "Cleaning any previously built kernel modules"
make clean 
echo "Building Kernel module"
make all 
sudo rmmod lister
sudo insmod *.ko 
sudo dmesg | grep Process
