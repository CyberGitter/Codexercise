VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "ThisWorkbook"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
'# 抽样需求
'
'以省份和信用等级两个维度，每个省份的每个信用等级分组（详见“透视表”）均抽取5个样本客户。这样，每个省份各抽取近30个样本客户。
'
'# 数据处理步骤
'
'1. 对于从系统中提取出来的原始客户清单，首先删除其中与抽样过程无关的字段，仅保留[省份]、[信用等级]、[客户代码]。这样做是为了便于人的观察分析、加快机器运行速度。
'2. 进一步地，用数据筛选删去无效值（例如空白值等），再删去重复值。
'3. 以[省份]为主要关键字、[信用等级]为次要关键字进行排序，其中[信用等级]的自定义序列按行内评级细则来确定。
'4. 以[省份]和[信用等级]两个维度生成数据透视表，并以SUM列对部分信用等级进行归并汇总。
'5. 运行VBA代码。
'6. 将抽样结果Excel工作表导出为txt文件，然后再由Access导入至一张独立的数据表。（之所以要借到txt文件中转，是为了避免直接复制粘贴到Access时，会自动转换为科学计数法数值，从而导致后续连接查询时，字段类型不匹配）
'7. 将去除了重复项的客户清单导入Access中的一张新的独立的数据表，与之前的抽样结果进行连接查询，补齐客户信息字段。
'8. 对信息已经补齐的样本客户表，以[省份]和[信用等级]两个维度来进行数据透视，检验抽样结果是否合乎需求。


Sub Sampling()
    Application.ScreenUpdating = False
    
    Dim Province As Long '省份
    Dim Rating As Long '信用等级
    
    Dim ClientNumber As Long '抽样过程中所所遍历到的客户累积数
    Dim SampleNumber As Long '抽取出来的样本累积数
    Dim Counter As Long
    
    Dim i As Long '就是普通的For循环计数器
    
    ClientNumber = 1 '从第1行客户开始（我删去了列标题）
    SampleNumber = 1 '从第1行开始记录抽样结果（我没写列标题）

    For Province = 2 To 38
        For Rating = 2 To 7
            Counter = Worksheets("透视表").Cells(Province, Rating).Value '当前省份与当前信用等级下的总客户数
            If Counter = 0 Then
                GoTo Continue
            ElseIf Counter <= 5 Then
                For i = 0 To Counter - 1
                    Worksheets("RESULT").Cells(SampleNumber + i, 1).Value = Worksheets("去除无效值与重复值并排序").Cells(ClientNumber + i, 3)
                Next i
                SampleNumber = SampleNumber + Counter
                ClientNumber = ClientNumber + Counter
                GoTo Continue
            Else
                For i = 0 To 4
                    Worksheets("RESULT").Cells(SampleNumber + i, 1).Value = WorksheetFunction.Index(Range(Worksheets("去除无效值与重复值并排序").Cells(ClientNumber, 3), Worksheets("去除无效值与重复值并排序").Cells(ClientNumber + Counter - 1, 3)), WorksheetFunction.RandBetween(1, Counter))
                Next i
                SampleNumber = SampleNumber + 5
                ClientNumber = ClientNumber + Counter
            End If
Continue:
        Next Rating
    Next Province
        
    Application.ScreenUpdating = True
End Sub
