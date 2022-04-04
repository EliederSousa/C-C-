# Visual Studio Code Tips

### Para instalar o MINGW

> https://sourceforge.net/projects/mingw/

Adicione no PATH do Windows:
> [caminhoDaInstalação]\bin  
> [caminhoDaInstalação]\msys\1.0\bin  
> 
Exemplo:
> C:\MinGW\bin  
> C:\MinGW\msys\1.0\bin  

Extensões para se instalar no VS Code:
> Code Runner  
> C C++

Após instalar o Code Runner, faça:
File > Preferences > Settings > Run Code Configuration > Code-runner: Run In Terminal > check

--------

### Para alternar entre a tela de cmd do VSCode e a tela do editor pelo atalho CTRL+':
> CTRL+SHIFT+P > open keyboard shortcuts (json)

Cole isto dentro do [ ... ]:  
// Toggle between terminal and editor focus  
// { "key": "ctrl+`", "command": "workbench.action.terminal.focus"},  
// { "key": "ctrl+`", "command": "workbench.action.focusActiveEditorGroup", "when": "terminalFocus"}  

--------

### Compilando múltiplos arquivos .cpp, usando Code Runner

1) Gere um arquivo tasks.json (CTRL+SHIFT+B)  
2a) Nele, coloque todos os arquivos .cpp que o linker deve usar:  

// Esse seria a main.cpp (ou o arquivo base que você está usando como principal)  
//"-g",  
//"${file}",  

// Esse seria um segundo arquivo .cpp, deve-se criar quantos desses houver no projeto.  
//"-g",  
//"Funcionario.cpp",  


2b) OU então, usar a diretiva:  

// Isso compilará todos os arquivos .cpp que ele encontrar na pasta do projeto  
"-g",  
"${workspaceFolder}\\*.cpp",  


LEMBRE-SE: se você deixar uma entrada ${file} e outra ${workspaceFolder} no mesmo tasks.json, ele tentará  
compilar os mesmos arquivos 2 vezes, dando erro de redeclaração. Deixe apenas um método ou outro (2a ou 2b)  


3) Usando o Code Runner, abra a configuração dele (settings.json) e adicione a seguinte diretiva:  
"code-runner.executorMap": {  
	"cpp": "cd $dir && g++ *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt",  
}  


Tente dar build usando CTRL+SHIFT+B, e veja se o build foi concluído. Assim, o CTRL+ALT+N funcionará sem erros.  
Isso eliminará a necessidade de utilizar include .cpp ao invés de .h (pois conserta os erros do linker).




