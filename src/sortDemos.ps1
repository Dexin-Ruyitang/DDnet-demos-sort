$demo=(Get-ChildItem -Path *.demo -Name)
foreach ($f in $demo) {
    $proc=Start-Process .\readTWDemoLenth.exe -ArgumentList """$f""" -NoNewWindow -Wait -PassThru
    $len = $proc.ExitCode
    if ($len -gt 0) {
        if ($len -lt 60) {
            Move-Item $f .\demo-01m\
        } elseif ($len -lt 300) {
            Move-Item $f .\demo-05m\
        } elseif ($len -lt 600) {
            Move-Item $f .\demo-10m\
        } elseif ($len -lt 1800) {
            Move-Item $f .\demo-30m\
        } elseif ($len -lt 3600) {
            Move-Item $f .\demo-60m\
        } elseif ($len -gt 3600) {
            Move-Item $f .\demo-60m+\
        }
    }
}