<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>Template rule</title>
            </head>
            <body>
                <h2>XSLT document</h2>
                <table border="1">
                    <tr>
                        <th>First note</th>
                        <th>Second note</th>
                    </tr>
                    <xsl:for-each select="catalog/note">
                        <xsl:sort select="abzac" />
                        <tr>
                            <td>
                                <xsl:value-of select="abzac" />
                            </td>
                            <td>
                                <xsl:value-of select="parag" />
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>