# sudo apt install git
# git clone http://github.com/rodinhart/linux.git
# cd linux
# sh start.sh
sudo apt-get update
sudo apt install git
sudo timedatectl set-timezone Europe/London
# setxkbmap uk
curl -o chrome.deb https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt install --assume-yes ./chrome.deb
sudo apt install --assume-yes clang
sudo apt install --assume-yes lld-8
sudo apt install --assume-yes nodejs
echo "All done!"
