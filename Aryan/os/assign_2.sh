#!bin/bash 
echo -e "\n\t\tWelcome to our Address Book !\n" 
while true 
do 
echo -e "Select your option : \n1.Enter data \n2.Display data\n3.Search using name\
 n4.Delete using name \n5.Modify using name\n6.Exit\n\t\t" 
read ch 
case $ch in 
1) 
while true 
do 
echo -e "\nEnter the record : " 
echo "Eno. : " 
read eno 
echo "Ename : " 
read ename 
while true 
do 
  echo "Mob no. : " 
  read mno 
  len=${#mno} 
  if test $len = 10 
  then 
break 
  else 
echo -e "\n\t\tInvalid number please enter again ! " 
  fi 
done 
echo "City : " 
read city 
echo -e "$eno\t$ename\t$mno\t$city" >> records.txt 
echo -e "\n\nDo you want to enter more records ? [y/n] : " 
read cho 
if test $cho = n 
then 
break 
 fi 
done 
echo -e "\n\t\t Records added succesfully !\n" 
;; 
2) if [[ -s records.txt ]] 
then 
echo -e "\n\n---------Records---------\n" 
cat records.txt 
echo -e "\n\n" 
else 
echo -e "\n\t\tFile is empty !\n" 
fi 
;; 
3) 
4) 
5) 
esac 
done 
echo -e "\nEnter the name to be searched : " 
read s_name 
echo 
grep -i $s_name records.txt 
echo
 ;; 
echo -e "\nEnter the name to be deleted : " 
read d_name 
#grep -v $d_name records.txt > temp 
#mv temp records.txt 
sed -i "/$d_name/d" records.txt 
echo -e "\n\t\t Record deleted succesfully !\n" 
;; 
echo -e "\nEnter the name for record to be modified : " 
read m_name 
no=`grep -n $m_name records.txt | cut -c 1` 
echo -e "\nEnter the value that you want to modify :" 
read m_value 
echo -e "\nEnter the new value : " 
read n_value 
sed -i "$no s/$m_value/$n_value/" records.txt 
echo -e "\n\t\t Record modified successfully !" 
;; 
*) 
echo -e "\nProgram Finished due to exit or wrong option !" 
break 2 
;; 
rm records.txt