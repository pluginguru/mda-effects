sln = open('mda_vst.sln', 'w')
for line in open('_mda_vst.sln').readlines():
    if not 'Win32' in line:
        sln.write(line)
sln.close()
