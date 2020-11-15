#!/bin/bash
echo " Дата: $(date)"
echo "Имя учетной записи: $(whoami)"
echo "Доменное имя учетной записи: $(hostname)"
echo "Процессор:"
echo " • Модель - $(cat /proc/cpuinfo | grep "model name" | uniq | awk '{print $3, $4, $5, $6, $7, $8, $9}')"
echo " • Архитектура: $(uname -m)"
echo " • Частота: $(cat /proc/cpuinfo | grep "cpu MHz" | uniq | awk '{print $4}')"
echo " • Кол-во ядер: $(cat /proc/cpuinfo | grep "cpu cores" | uniq | awk '{print $4}')"
echo " • Кол-во потоков на одно ядро: $(cat /proc/cpuinfo | grep "siblings" | uniq | awk '{print $3}')"
echo "Оперативная память:"
echo " • Всего - $(cat /proc/meminfo | grep "MemTotal" | awk '{print $2, $3}')"
echo " • Доступно - $(cat /proc/meminfo | grep "MemFree" | awk '{print $2, $3}')"
echo "Жесткий диск:"
echo " • $(df -h)"
echo " • SWAP всего – $(cat /proc/meminfo | grep "SwapTotal" | awk '{print $2, $3}')"
echo " • SWAP доступно – $(cat /proc/meminfo | grep "SwapFree" | awk '{print $2, $3}')"
echo "Сетевые интерфейсы:"
echo " •Кол-во сетевых интерфейсов - "
echo "$(ip a |grep -i inet | awk '{print $7, $2}')"