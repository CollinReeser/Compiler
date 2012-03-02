git checkout develEnvSimp
echo -e "\nNOTE: Current working branch is now \"develEnvSimp\"\n"
ls -A | xargs git add
git commit -a
git push -u origin develEnvSimp
