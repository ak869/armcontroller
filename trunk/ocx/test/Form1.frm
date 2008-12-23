VERSION 5.00
Object = "{1C19F271-4C93-4F4B-8422-308103ED3887}#1.0#0"; "AnvizOcx.dll"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin AnvizOcxLibCtl.Anviz Anviz1 
      Height          =   735
      Left            =   1200
      OleObjectBlob   =   "Form1.frx":0000
      TabIndex        =   0
      Top             =   1440
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Form_Load()
    Dim amj As New AnvizOcxLibCtl.AMJ03
    Dim dgs As AnvizOcxLibCtl.DoorGroups
    Dim dg As AnvizOcxLibCtl.DoorGroup
    Dim tl As AnvizOcxLibCtl.TimeList
    Dim tls As AnvizOcxLibCtl.TimeLists
    Dim b As Boolean
    Set dgs = amj.DoorGroups
    Set dg = dgs.Item(1)
    Set tls = dg.TimeLists
    Set tl = tls.Item(1)
    Set tls = Nothing
    Set dg = Nothing
    b = tl.IsDay(Fri)
    
    
End Sub
