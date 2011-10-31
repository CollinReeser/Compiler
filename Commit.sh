cp Commit.sh gitCompiler/
cp -r compileSegments gitCompiler/
cp -r LexParse gitCompiler/
cp -r tests gitCompiler/
cp -r utilities gitCompiler/
cp -r asm gitCompiler/
cp Makefile gitCompiler/

cd gitCompiler
ls | xargs git add
git commit -a
git push -u origin master
