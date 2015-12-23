<div class="text-center">
    <h1>Hello <?= htmlspecialchars($username) ?></h1>
    <h4>Your balance is $<?= htmlspecialchars($cash) ?></h4>       
</div>
<div class="text-center">
    <?php if (empty($positions)): ?>
        <h4>Your portfolio is empty</h4>
    <?php else: ?>    
        <h2>Your portfolio:</h2>
        <table class="table text-left">
            <thead>
                <tr>
                    <th>Symbol</th>
                    <th>Shares</th>
                    <th>Price</th>
                    <th>Total</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach($positions as $position): ?>
                    <tr>
                        <td><?= $position["symbol"] ?></td>
                        <td><?= $position["shares"] ?></td>
                        <td><?= $position["price"] ?></td>
                        <td><?= $position["price"] * $position["shares"] ?>
                    </tr>
                <?php endforeach ?>    
            </tbody>
        </table>
    <?php endif ?>   
</div>
<div>
    <a href="logout.php">Log Out</a>
</div>
