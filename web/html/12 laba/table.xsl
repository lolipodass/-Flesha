<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>Аттестация</title>
            </head>
            <body>
                <h1>Аттестация</h1>
                <table border="1">
                    <tr>
                        <th>Name</th>
                        <th>Surname</th>
                        <th>Mark</th>
                    </tr>
                    <xsl:for-each select="catalog/student">
                        <xsl:sort order="descending" select="mark" />
                        <tr>
                            <xsl:choose>
                                <xsl:when test="mark &gt; 8">
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="surname" />
                                    </td>
                                    <td style="background-color:green">
                                        <xsl:value-of select="mark" />
                                    </td>
                                </xsl:when>
                                <xsl:when test="mark &lt; 4">
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="surname" />
                                    </td>
                                    <td style="background-color:red">
                                        <xsl:value-of select="mark" />
                                    </td>
                                </xsl:when>
                                <xsl:otherwise>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="surname" />
                                    </td>
                                    <td>
                                        <xsl:value-of select="mark" />
                                    </td>
                                </xsl:otherwise>
                            </xsl:choose>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>