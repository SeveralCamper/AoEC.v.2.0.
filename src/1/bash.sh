#! /bin/bash

date
whoami
hostname
echo Процессор:
cat /proc/cpuinfo | sed '5!d'
lscpu | sed '1!d'
cat /proc/cpuinfo | sed '7!d'
cat /proc/cpuinfo | sed '12!d'
lscpu | sed '7!d'
echo Оперативная память:
free
echo Жесктий диск:
sudo fdisk -l | sed '51!d'
sudo fdisk -l | sed '52!d'
sudo fdisk -l | sed '53 !d'
sudo fdisk -l | sed '54!d'
sudo fdisk -l | sed '55!d'
echo
df -h | sed '1!d'
df -h | sed '4!d'
echo SWAP:
swapon -s
echo Сетевые интерфейсы:\n
echo "Количество интерфейсов: $(ls /sys/class/net/ | wc -l)"
echo -e "\nИмя сетевого интерфейса\t\tMAC адрес\t\tIP адрес\t\tСкорость соединения"
for var in /sys/class/net/*; do
  echo -ne "${var##*/}\t\t\t\t"
  tr "\n" "\t" < "$var/address"
  printf "%-24s" "$(ip -4 -o a | grep " ${var##*/} " | tr -s ' ' | cut -d' ' -f4 | tr -d '\n')"
  ip -4 -0 a | grep " ${var##*/}: " | tr -s ' ' | cut -d' ' -f13
done



# sudo fdisk -l
