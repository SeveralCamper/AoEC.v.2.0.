#! /bin/bash

date
whoami
hostname
echo
echo Процессор:
echo
cat /proc/cpuinfo | sed '5!d'
lscpu | sed '1!d'
cat /proc/cpuinfo | sed '7!d'
cat /proc/cpuinfo | sed '12!d'
lscpu | sed '7!d'
echo
echo Оперативная память:
echo
echo -ne "Всего: "
free -h | grep "Память:" | tr -s ' ' | cut -d' ' -f2
echo -ne "Доступно: "
free -h | grep "Память:" | tr -s ' ' | cut -d' ' -f7
echo
echo Жесктий диск:
echo

hardDrive=$(df -h 2> /dev/null| grep '/$')

echo "Жесткий диск:"
echo "Всего – $(echo "$hardDrive" | awk '{ print $2 }')"
echo "Доступно – $(echo "$hardDrive" | awk '{ print $4 }')"
echo "Смонтировано в корневую директорию / – $(echo "$hardDrive" | awk '{ print $1 }')"
echo "SWAP всего: $(free -h | grep "Подкачка:" | tr -s ' ' | cut -d' ' -f2)"
echo "SWAP доступно: $(free -h | grep "Подкачка:" | tr -s ' ' | cut -d' ' -f4)"

echo
echo Сетевые интерфейсы:
echo
echo "Количество интерфейсов: $(ls /sys/class/net/ | wc -l)"
echo -e "\nИмя сетевого интерфейса\t\tMAC адрес\t\tIP адрес\t\tСкорость соединения"
for var in /sys/class/net/*; do
  echo -ne "${var##*/}\t\t\t\t"
  tr "\n" "\t" < "$var/address"
  printf "%-24s" "$(ip -4 -o a | grep " ${var##*/} " | tr -s ' ' | cut -d' ' -f4 | tr -d '\n')"
  ip -4 -0 a | grep " ${var##*/}: " | tr -s ' ' | cut -d' ' -f13
done



# sudo fdisk -l
