from __future__ import annotations
from os import path
import os
import subprocess


def loadenv(name: str) -> dict[str, str]:
	d = {}
	with open(name, "rt", encoding="gb2312") as fid:
		for line in fid:
			line = line.strip()
			i = line.find("=")
			k, v = line[:i], line[i + 1:]
			if len(v) > 0:
				d[k] = v.replace('\\\\', '\\')
	return d


"""
vcvars64.bat 执行一次要 2-3 秒
执行一次脚本，把对环境变量的改变保存下来
"""

bat = [
	'set > 1.ini',
	'"C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"',
	'set > 2.ini'
]
subprocess.run(" && ".join(bat), shell=True)
A = loadenv("1.ini")
B = loadenv("2.ini")
cmd, ps1 = {}, {}
for k, v in B.items():
	if k not in A:
		if not k.startswith("__"):
			ps1[k] = cmd[k] = v
	else:
		a, b = A[k], B[k]
		if (a != b):
			cmd[k] = b.replace(a, f"%{k}%")
			ps1[k] = b.replace(a, f"$env:{k}")
os.remove("1.ini")
os.remove("2.ini")
with open(".vscode\\clenv.cmd", "wt", encoding="gb2312") as fid:
	fid.write("""
@echo off
if defined VSCMD_ARG_TGT_ARCH ( exit /b 0 )
echo set clenv
""")
	for k, v in cmd.items():
		fid.write(f'set {k}={v}\n')
with open(".vscode\\clenv.ps1", "wt", encoding="gb2312") as fid:
	fid.write("""
if (Test-Path env:VSCMD_ARG_TGT_ARCH) { return }
Write-Host set clenv
""")
	for k, v in ps1.items():
		fid.write(f'$env:{k}="{v}"\n')
