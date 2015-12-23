<!DOCTYPE html>

<html>

    <head>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/>
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.11.1.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <a href="/"><img alt="C$50 Finance" src="/img/logo.gif"/></a>
            </div>
            <?php if (!empty($_SESSION["id"])): ?>
            <div class="text-center">
                <a href="/" class="btn btn-default" role="button">Home</a>
                <a href="/quote.php" class="btn btn-default" role="button">Quote</a>
                <a href="/sell.php" class="btn btn-default" role="button">Sell</a>
                <a href="/buy.php" class="btn btn-default" role="button">Buy</a>
                <a href="/history.php" class="btn btn-default" role="button">History</a>
                <a href="/settings.php" class="btn btn-default" role="button">Settings</a>
            </div>
            <?php endif ?>
            

            <div id="middle">
