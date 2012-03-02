git checkout master
echo -e "\nNOTE: Current working branch is now \"master\"\n"
ls -A | xargs git add
git commit -a
git push -u origin master
