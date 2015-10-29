VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "Sheet4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Sub Sampling()
    Application.ScreenUpdating = False
    
    Dim CounterA As Long
    Dim CounterB As Long
    
    Dim SampleNumber As Long
    Dim ClientNumber As Long
    
    Dim Name As String
    
    Name = Worksheets("正式抽样客户表").Cells(1, 2)

    For CounterA = 2 To 213212
        If Worksheets("正式抽样客户表").Cells(CounterA, 2) = Name Then
            GoTo continue
        Else
            SampleNumber = Application.WorksheetFunction.VLookup(Cells(CounterA, 2), Worksheets("样本分配表").Range("B:C"), 2, 0)
            ClientNumber = Application.WorksheetFunction.VLookup(Cells(CounterA, 2), Worksheets("正式抽样一级支行客户数").Range("A:B"), 2, 0)
            For CounterB = CounterA To CounterA + SampleNumber * 2 - 1
                Worksheets("正式抽样客户表").Cells(CounterB, 4).Value = Application.WorksheetFunction.Index(Range(Cells(CounterA, 1), Cells(CounterA + ClientNumber - 1, 1)), Application.WorksheetFunction.RandBetween(1, ClientNumber))
                Worksheets("正式抽样客户表").Cells(CounterB, 5).Value = Application.WorksheetFunction.Index(Range(Cells(CounterA, 1), Cells(CounterA + ClientNumber - 1, 1)), Application.WorksheetFunction.RandBetween(1, ClientNumber))
            Next CounterB
            Name = Worksheets("正式抽样客户表").Cells(CounterA, 2)
        End If
continue:
    Next CounterA
        
    Application.ScreenUpdating = True
End Sub
