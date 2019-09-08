projectList= [
    [ 'Ambience', 'FB4E8CEE-4576-401C-A97E-E353C44B6032' ],
    [ 'Bandisto', '95FC53A4-AAC1-44FE-8F89-940AEB157DE1' ],
    [ 'BeatBox', '32A35CE0-456D-48BF-9FF6-EA0DA09ADE7E' ],
    [ 'Combo', 'E36A56F0-BE42-470F-8769-E1553F6B6B39' ],
    [ 'DeEss', '318EEA04-FCDB-4C87-A083-1650D6968FF3' ],
    [ 'Degrade', '3F2FE336-1EC7-4A5D-8A70-0E2F9FA482F3' ],
    [ 'Delay', 'A56D5788-2B5F-44CE-BE31-AA121854880D' ],
    [ 'Detune', 'EAD7038D-4BF5-4B1D-BAA6-DD326DBE50D3' ],
    [ 'Dither', 'FE5E0B29-E8D0-4C7B-B125-918E22760213' ],
    [ 'DubDelay', '8C13A5F2-A61E-4996-9571-74C71CF8E514' ],
    [ 'DX10', '8A2B47A5-692A-49C4-A6F2-5B5AB2FA63A0' ],
    [ 'Dynamics', '4B6F8B6A-5CAC-4C82-86D7-CECB46123596' ],
    [ 'ePiano', 'E690AA48-7771-4890-A778-4D1F39287BF1' ],
    [ 'Image', '6B616B46-4D10-46A1-B36D-1B9A27EFFC8D' ],
    [ 'JX10', '09446102-1AFF-4937-8E2F-C8EF1678DF71' ],
    [ 'Leslie', '520AC083-0E34-44D2-9DAE-058312A4E097' ],
    [ 'Limiter', '0A1666DD-B1D1-4031-8EFA-D86461FA5D0B' ],
    [ 'Looplex', '5EE3E91A-359D-4FF8-A9A3-DA289E5B44E7' ],
    [ 'Loudness', 'C4D3A095-2D71-4DCE-806B-1BD381D34B54' ],
    [ 'MultiBand', '8F827951-F2BD-4A3C-AB4F-74F6BA1034BA' ],
    [ 'Overdrive', '0BB13495-2C0A-458D-B09F-5AA9918EBD2F' ],
    [ 'Piano', '0E324D7F-CFFE-4BEB-9402-BAEF80A3CA3D' ],
    [ 'RePsycho!', 'E940A746-65D2-493A-BFA8-071A8DC97484' ],
    [ 'RezFilter', '370D98C9-13FF-4EFD-8C40-3271DBC49CA8' ],
    [ 'RingMod', '19803485-24A6-438B-A9ED-49B07A020D2B' ],
    [ 'RoundPan', 'A08D00BC-3A44-4228-A038-60B2B4234A34' ],
    [ 'Shepard', '4C0FBB7A-7AAB-4627-BFFE-E6DE1F91724D' ],
    [ 'Splitter', '0887BA3E-77B7-4BC0-A7CF-047935F8A171' ],
    [ 'Stereo', '3BB87A27-4C7C-4315-ABDB-FFE67BFA7F87' ],
    [ 'SubSynth', 'C15528A8-2CF7-4F7E-92C0-E341A5BC9A5A' ],
    [ 'TalkBox', '56B68EB3-A0E7-4774-9CB5-4C04E94709C7' ],
    [ 'TestTone', '1380896C-BBEF-4002-8B5F-E7960C693AA2' ],
    [ 'ThruZero', '8D951236-0515-4372-8932-EC9EEB4AC4EF' ],
    [ 'Tracker', '8126931B-1709-4811-8A08-A0D61B65C06B' ],
    [ 'Transient', 'D237E487-AB16-4FB5-8FE6-DDCA95319EF5' ],
    [ 'VocInput', 'ED6929F9-DFD2-4E71-8823-E2E9B5CD7BA8' ],
    [ 'Vocoder', 'B41227FF-05FC-4291-8D5B-C150DA91D12B' ]
]

project = open('mda Ambience.vcxproj').readlines()
filters = open('mda Ambience.vcxproj.filters').readlines()
user = open('mda Ambience.vcxproj.user').readlines()

for [ name, guid ] in projectList[1:]:
    print name
    
    file = open('mda ' + name + '.vcxproj', 'w')
    for line in project:
        file.write(line.replace('FB4E8CEE-4576-401C-A97E-E353C44B6032', guid).replace('Ambience', name))
    file.close()

    file = open('mda ' + name + '.vcxproj.filters', 'w')
    for line in filters:
        file.write(line.replace('Ambience', name))
    file.close()

    file = open('mda ' + name + '.vcxproj.user', 'w')
    for line in user:
        file.write(line)
    file.close()
