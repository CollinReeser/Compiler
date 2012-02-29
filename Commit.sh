cp -u -v Commit.sh gitCompiler/
cp -u -v .gitignore gitCompiler/
cp -u -v Pull.sh gitCompiler/
cp -r -u -v compileSegments gitCompiler/
cp -r -u -v LexParse gitCompiler/
cp -r -u -v tests gitCompiler/
cp -r -u -v utilities gitCompiler/
cp -r -u -v asm gitCompiler/
cp -u -v Makefile gitCompiler/

cd gitCompiler
ls -A | xargs git add
git commit -a
git push -u origin master
