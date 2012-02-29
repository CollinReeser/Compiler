cp -u Commit.sh gitCompiler/
cp -u Push.sh gitCompiler/
cp -r -u compileSegments gitCompiler/
cp -r -u LexParse gitCompiler/
cp -r -u tests gitCompiler/
cp -r -u utilities gitCompiler/
cp -r -u asm gitCompiler/
cp -u Makefile gitCompiler/

cd gitCompiler
ls | xargs git add
git commit -a
git push -u origin master
